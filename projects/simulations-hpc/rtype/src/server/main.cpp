/*
** EPITECH PROJECT, 2024
** Rtype draft
** File description:
** main.cpp
*/

#include "UdpServer.hpp"
#include "../Protocol/Protocol.hpp"
#include "../Protocol/Requests/Request.hpp"
#include "../Protocol/Requests/SendGameEvent.hpp"
#include <iostream>
#include <asio.hpp>
#include "ECS/ECS.hpp"
#include "Track.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Velocity.hpp"
#include "ECS/Components/Player.hpp"
#include "ECS/Components/Enemy.hpp"
#include "ECS/Components/Projectiles.hpp"
#include "ECS/Components/RigidBody.hpp"
#include "ECS/Components/Health.hpp"
#include "ECS/Components/State.hpp"
#include "ECS/Components/Boss.hpp"
#include "ECS/Systems/StateControl.hpp"
#include "ECS/Systems/Collision.hpp"

#include "Parser.hpp"
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {
    uint16_t port = 12345;  // Port par défaut

    Parser parser;
    Track trk;
    ECS ecs(trk);

    Track &track = ecs.getTrack();

    CLO options = parser.parseCommandLine(argc, argv);
    port = options.port;

    ecs.addComponent(std::make_shared<Position>());
    ecs.addComponent(std::make_shared<Velocity>());
    ecs.addComponent(std::make_shared<Player>());
    ecs.addComponent(std::make_shared<Enemy>());
    ecs.addComponent(std::make_shared<Projectiles>());
    ecs.addComponent(std::make_shared<Health>());
    ecs.addComponent(std::make_shared<RigidBody>());
    ecs.addComponent(std::make_shared<State>());
    ecs.addComponent(std::make_shared<Boss>());

    ecs.addSystem(std::make_shared<Motion>());
    ecs.getElement<Motion>(0)->addComponent(ecs.getElement<Position>(0));
    ecs.getElement<Motion>(0)->addComponent(ecs.getElement<Velocity>(0));

    ecs.addSystem(std::make_shared<Collision>());
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Projectiles>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<RigidBody>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Position>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Health>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<State>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Boss>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Player>(0));
    ecs.getElement<Collision>(0)->addComponent(ecs.getElement<Enemy>(0));

    ecs.addSystem(std::make_shared<StateControl>());
    ecs.getElement<StateControl>(0)->addComponent(ecs.getElement<State>(0));
    ecs.getElement<StateControl>(0)->addComponent(ecs.getElement<Position>(0));
    ecs.getElement<StateControl>(0)->addComponent(ecs.getElement<Health>(0));
    ecs.getElement<StateControl>(0)->addComponent(ecs.getElement<Enemy>(0));

    try {
        asio::io_context io_context;
        UdpServer server(io_context, port);

        server.start(ecs);

        std::cout << "Serveur démarré sur le port " << port << ". Appuyez sur Entrée pour arrêter...\n";
        std::thread io_thread([&io_context]() { io_context.run(); });

        int fps = 60;
        int updateFreq = std::max(1000 / fps, 1);

        bool serverIsRunning = true;

        while (serverIsRunning) {
            auto start = std::chrono::system_clock::now();
            auto end = start;
            auto current = start;

            auto transition = std::chrono::milliseconds(0);

            bool locker = false;
            bool frameLock = false;

            std::shared_ptr<Player> player = ecs.getElement<Player>(0);
            if (player == nullptr) {
                std::cerr << "Player component not found!" << std::endl;
                continue;
            }
            while (player->getEntities().size() <= 0)
                std::this_thread::sleep_for(std::chrono::seconds(1));
            for (auto &e : ecs.getClients()) {
                std::vector<field_t> fields = {};
                fields.push_back({RequestType::r_SendGameEvent, 8});
                fields.push_back({(uint16_t)e.first, 16});
                fields.push_back({(uint16_t)EventType::evt_gameStart, 8});
                server.sendRequestTo(ecs, fields, e.second);
            }
            while (true) {
                try {
                    std::shared_ptr<Health> health = ecs.getElement<Health>(0);
                    if (health == nullptr) {
                        std::cout << "Health component not found" << std::endl;
                        continue;
                    }
                    std::shared_ptr<Enemy> enemy = ecs.getElement<Enemy>(0);
                    if (enemy == nullptr) {
                        std::cerr << "Enemy component not found!" << std::endl;
                        continue;
                    }
                    int alivePlayers = 0;
                    for (auto &p : ecs.getClients())
                        if (health->getHealth(p.first) > 0)
                            alivePlayers++;
                    if (alivePlayers < 1) {
                        for (auto &e : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendGameEvent, 8});
                            fields.push_back({(uint16_t)e.first, 16});
                            fields.push_back({(uint16_t)EventType::evt_gameOver, 8});
                            server.sendRequestTo(ecs, fields, e.second);
                        }

                        for (auto &entity : ecs.getEntities())
                            ecs.dropEntity(entity.first);
                        track.reset();
                        enemy->setNbSpawned(0);
                        enemy->setNbKilled(0);
                        for (auto &p : player->getEntities())
                            player->setNbKills(p.first, 0);
                        break;
                    }

                    if (track.getCurrentLevel() >= track.getLevels().size()) {
                        for (auto &c : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendGameEvent, 8});
                            fields.push_back({(uint16_t)c.first, 16});
                            fields.push_back({(uint16_t)EventType::evt_gameWon, 8});
                            server.sendRequestTo(ecs, fields, c.second);
                        }
                        std::cout << "Congratulation, you finished the game !!!" << std::endl;

                        for (auto &e : ecs.getEntities())
                            ecs.dropEntity(e.first);
                        track.reset();
                        enemy->setNbSpawned(0);
                        enemy->setNbKilled(0);
                        for (auto &p : player->getEntities())
                            player->setNbKills(p.first, 0);
                        break;
                    }
                    current = std::chrono::system_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - start);

                    if (elapsed.count() % updateFreq == 0) {
                        frameLock = false;
                        continue;
                    }
                    if (frameLock)
                        continue;
                    frameLock = true;

                    std::shared_ptr<State> state = ecs.getElement<State>(0);
                    if (state == nullptr) {
                        std::cerr << "State component not found!" << std::endl;
                        continue;
                    }

                    std::shared_ptr<Projectiles> proj = ecs.getElement<Projectiles>(0);
                    if (proj == nullptr) {
                        std::cerr << "Projectile component not found!" << std::endl;
                        continue;
                    }

                    Level &level = track.getLevel(track.getCurrentLevel());

                    level.setKilledEnemies(enemy->getNbKilled());
                    if (level.getKilledEnemies() >= level.getNbEnemies() && !locker) {
                        std::size_t totalPlayerKills = 0;
                        for (auto &p : player->getEntities())
                            totalPlayerKills += player->getNbKills(p.first);
                        if (totalPlayerKills < level.getNbEnemies() * 0.75) {
                            for (auto &c : ecs.getClients()) {
                                std::vector<field_t> fields = {};
                                fields.push_back({RequestType::r_SendGameEvent, 8});
                                fields.push_back({(uint16_t)c.first, 16});
                                fields.push_back({(uint16_t)EventType::evt_gameOver, 8});
                                server.sendRequestTo(ecs, fields, c.second);
                            }
                            std::cout << "You lost the game !!!" << std::endl;

                            for (auto &e : ecs.getEntities())
                                ecs.dropEntity(e.first);

                            track.reset();
                            enemy->setNbSpawned(0);
                            enemy->setNbKilled(0);

                            for (auto &p : player->getEntities())
                                player->setNbKills(p.first, 0);
                            locker = true;
                            break;    
                        }
                        enemy->setNbKilled(0);
                        enemy->setNbSpawned(0);

                        end = current;
                        locker = true;
                        std::cout << "Level \"" + level.getName() << "\" completed in " << elapsed.count() / 1000 << "s" << std::endl;
                    }

                    // std::cout << "duration: " << transition.count() << std::endl;
                    if (locker && transition.count() < level.getTransitionDuration() * 1000) {
                        transition = std::chrono::duration_cast<std::chrono::milliseconds>(current - end);
                        for (auto &c : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendGameEvent, 8});
                            fields.push_back({(uint16_t)c.first, 16});
                            fields.push_back({(uint16_t)EventType::evt_LevelEnd, 8});
                            server.sendRequestTo(ecs, fields, c.second);
                        }
                    } else if (locker) {
                        transition = std::chrono::milliseconds(0);
                        locker = false;
                        track.nextLevel();
                        start = std::chrono::system_clock::now();
                        for (auto &c : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendGameEvent, 8});
                            fields.push_back({(uint16_t)c.first, 16});
                            fields.push_back({(uint16_t)EventType::evt_LevelStart, 8});
                            server.sendRequestTo(ecs, fields, c.second);
                        }
                    }

                    for (auto &c : ecs.getClients()) {
                        for (auto &e : ecs.getEntities()) {
                            // si le client se connecte, on envoie les infos de toutes les entités de la map
                            if (!ecs.isConnected(c.first)) {
                                std::vector<field_t> fields = {};
                                fields.push_back({RequestType::r_SendNewEntity, 8});
                                fields.push_back({(uint16_t)e.first, 16});
                                server.sendRequestTo(ecs, fields, c.second);
                            }
                            // on envoie le déplacement au player
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendEntityPos, 8});
                            fields.push_back({(uint16_t)e.first, 16});
                            fields.push_back({0, (1024 - 16 - 8) / 8});
                            server.sendRequestTo(ecs, fields, c.second);

                            // on envoie la vie au player
                            fields = {};
                            fields.push_back({RequestType::r_SendHealth, 8});
                            fields.push_back({(uint16_t)e.first, 16});
                            fields.push_back({0, (1024 - 16 - 8) / 8});
                            server.sendRequestTo(ecs, fields, c.second);
                        }
                        // partage de l'id de la nouvelle entité à tous les clients
                        if (!ecs.isConnected(c.first)) {
                            ecs.connect(c.first);
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendNewEntity, 8});
                            fields.push_back({(uint16_t)c.first, 16});
                            server.sendRequestToAllClients(ecs, fields);
                        }
                    }

                    std::shared_ptr<Position> pos = ecs.getElement<Position>(0);
                    ecs.update();

                    int range = level.getLevelDuration() * 1000.0f * ecs.getDeltaTime() / std::max((float)level.getNbEnemies(), 1.0f) * level.getEnemySpeed() / 2;

                    if (rand() % (range > 0 ? range : 1) == 0 && enemy->getNbSpawned() < level.getNbEnemies() && !locker) {
                        unsigned int id = ecs.getAvailableSlot();
                        ecs.addEntity(id, std::make_shared<Entity>());
                        enemy->addEntity(id, ecs.getElement<Entity>(id, true));

                        if (pos == nullptr) {
                            std::cerr << "Position component not found!" << std::endl;
                            continue;
                        }
                        pos->addEntity(id, ecs.getElement<Entity>(id, true));
                        pos->setX(id, 1920);
                        pos->setY(id, std::rand() % 1080);
                        pos->addEntity(id, ecs.getElement<Entity>(id, true));

                        std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);
                        if (vel == nullptr) {
                            std::cerr << "Velocity component not found!" << std::endl;
                            continue;
                        }
                        vel->addEntity(id, ecs.getElement<Entity>(id, true));
                        vel->setSpeed(id, level.getEnemySpeed());
                        vel->setDir(id, 3.1415926535);

                        std::shared_ptr<RigidBody> rig = ecs.getElement<RigidBody>(0);
                        if (rig == nullptr) {
                            std::cerr << "RigidBody component not found!" << std::endl;
                            continue;
                        }
                        rig->addEntity(id, ecs.getElement<Entity>(id, true));
                        rig->setBody(id, sf::FloatRect(pos->getX(id), pos->getY(id), 100, 100));

                        std::shared_ptr<Health> health = ecs.getElement<Health>(0);
                        if (health == nullptr) {
                            std::cerr << "Health component not found!" << std::endl;
                            continue;
                        }
                        health->addEntity(id, ecs.getElement<Entity>(id, true));
                        health->setHealth(id, level.getEnemyHP());
                        health->setMinHealth(id, 0);
                        health->setMaxHealth(id, level.getEnemyHP());

                        state->addEntity(id, ecs.getElement<Entity>(id, true));
                        state->setState(id, StateType::ALIVE);

                        if (enemy->getNbSpawned() == level.getNbEnemies() - 1) {
                            std::cout << "mean time between spawns: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                                current - end).count() / 1000.0f / level.getNbEnemies() << std::endl;
                            // spawn du boss
                            std::shared_ptr<Boss> boss = ecs.getElement<Boss>(0);
                            if (boss == nullptr) {
                                std::cerr << "Boss component not found!" << std::endl;
                                continue;
                            }
                            boss->addEntity(id, ecs.getElement<Entity>(id, true));
                            health->setHealth(id, level.getBossHP());
                            health->setMinHealth(id, 0);
                            health->setMaxHealth(id, level.getBossHP());
                        }

                        for (auto &c : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendNewEntity, 8});
                            fields.push_back({id, 16});
                            server.sendRequestTo(ecs, fields, c.second);
                        }

                        enemy->addSpawn();
                    }

                    for (auto &pr : proj->getEntities()) {
                        if (pr.second == nullptr
                        || state->getEntity(pr.first) == nullptr
                        || state->getState(pr.first) != StateType::UNDEFINED)
                            continue;
    
                        for (auto &c : ecs.getClients()) {
                            std::vector<field_t> fields = {};
                            fields.push_back({RequestType::r_SendNewEntity, 8});
                            fields.push_back({(uint16_t)pr.first, 16});
                            server.sendRequestTo(ecs, fields, c.second);
                        }
                    }

                    // handle entity despawn
                    for (auto &e : state->getEntities())
                        if (state->getState(e.first) == StateType::DEAD) {
                            for (auto &c : ecs.getClients()) {
                                std::vector<field_t> fields = {};
                                fields.push_back({RequestType::r_DeleteEntity, 8});
                                fields.push_back({(uint16_t)e.first, 16});
                                server.sendRequestTo(ecs, fields, c.second);
                            }
                            ecs.dropEntity(e.first);
                        }

                } catch (const std::exception& e) {
                    std::cerr << "Erreur: " << e.what() << "\n";
                }
            }
        }
        server.stop();
        io_context.stop();
        io_thread.join();
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << "\n";
    }
    return 0;
}
