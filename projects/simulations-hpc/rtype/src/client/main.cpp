#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Components/Sprite.hpp"
#include "menu.hpp"
#include "System/Render.hpp"
#include "UdpClient.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <bitset>
#include <filesystem>
#include "Components/Sprite.hpp"
#include "Components/LifeBar.hpp"
#include "Components/EventMessage.hpp"

#include "../server/ECS/Components/Boss.hpp"
#include "../server/ECS/Components/Enemy.hpp"
#include "../server/ECS/Components/Health.hpp"
#include "../server/ECS/Components/Projectiles.hpp"

#include <fstream>

std::string loadShipFromJson(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open())
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filePath);

    std::string line;
    std::string shipKey = "\"ship\":";
    std::string shipName;
    bool foundShip = false;

    while (std::getline(file, line)) {
        size_t pos = line.find(shipKey);
        if (pos != std::string::npos) {
            pos += shipKey.size();

            while (pos < line.size() && (line[pos] == ' ' || line[pos] == '\"'))
                pos++;
            
            while (pos < line.size() && line[pos] != '\"')
                shipName += line[pos++];

            foundShip = true;
            break;
        }
    }

    file.close();

    if (!foundShip || shipName.empty())
        throw std::runtime_error("Clé 'ship' introuvable ou vide dans le fichier.");

    return shipName;
}

int main() {
    try {
        Track track;
        ECS ecs(track);
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");

        // set music
        sf::Music music;
        // find the first music in the folder
        std::string musicPath = "src/client/assets/music/";
        for (const auto& entry : std::filesystem::directory_iterator(musicPath))
            if (entry.is_regular_file() && (entry.path().extension() == ".wav" || entry.path().extension() == ".mp3")) {
                musicPath = entry.path().string();
                break;
            }

        if (!music.openFromFile(musicPath))
            throw std::runtime_error("Impossible d'ouvrir le fichier de musique.");
        music.setLoop(true);
        music.play();

        ecs.addComponent(std::make_shared<Boss>());
        ecs.addComponent(std::make_shared<Sprite>());
        ecs.addComponent(std::make_shared<LifeBar>());
        ecs.addComponent(std::make_shared<Health>());
        ecs.addComponent(std::make_shared<Player>());
        ecs.addComponent(std::make_shared<Enemy>());
        ecs.addComponent(std::make_shared<Position>());
        ecs.addComponent(std::make_shared<Velocity>());
        ecs.addComponent(std::make_shared<Projectiles>());
        ecs.addComponent(std::make_shared<EventMessage>());

        ecs.addSystem(std::make_shared<Render>(window));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<Boss>(0));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<Sprite>(0));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<Health>(0));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<LifeBar>(0));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<Position>(0));
        ecs.getElement<Render>(0)->addComponent(ecs.getElement<EventMessage>(0));

        UdpClient client("127.0.0.1", 12345, ecs);
        Menu menu(window, ecs);

        std::string shipName = loadShipFromJson("src/client/assets/settings.json");
        if (shipName == "Red Falco")
            ecs.getElement<Sprite>(0)->setTexture("player", "src/client/assets/player.png");
        else if (shipName == "White Eagle")
            ecs.getElement<Sprite>(0)->setTexture("player", "src/client/assets/white.png");

        ecs.getElement<Sprite>(0)->setTexture("boss", "src/client/assets/boss.png");
        ecs.getElement<Sprite>(0)->setTexture("enemy", "src/client/assets/enemy.png");
        ecs.getElement<Sprite>(0)->setTexture("projectile", "src/client/assets/projectile.png");

        client.start();

        std::string input = "Player";
        std::vector<field_t> fields;
        fields.push_back({2, 8});
        for (int i = 0; i < input.size(); i++)
            fields.push_back({static_cast<uint16_t>(input[i]), 8});
        fields.push_back({static_cast<uint16_t>(0), 8});
        client.addRequest(fields);
        menu.run(client);
        client.stop();
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
