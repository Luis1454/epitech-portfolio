/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ReceiveName
*/

#include "ReceiveName.hpp"
#include "../../server/ECS/Components/Player.hpp"
#include "../../server/ECS/Components/Velocity.hpp"
#include "../../server/ECS/Components/Health.hpp"
#include "../../server/ECS/Components/RigidBody.hpp"
#include "../../server/ECS/Components/State.hpp"

template<typename T>
ReceiveName<T>::ReceiveName()
{
    this->_type = "Receive Name";
}

template <typename T>
void ReceiveName<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    std::shared_ptr<Position> pos = ecs.getElement<Position>(0);
    if (pos == nullptr) {
        std::cerr << "Position component not found!" << std::endl;
        return;
    }
    std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);
    if (vel == nullptr) {
        std::cerr << "Velocity component not found!" << std::endl;
        return;
    }
    std::shared_ptr<Health> health = ecs.getElement<Health>(0);
    if (health == nullptr) {
        std::cerr << "Health component not found!" << std::endl;
        return;
    }
    std::shared_ptr<Player> player = ecs.getElement<Player>(0);
    if (player == nullptr) {
        std::cerr << "Player component not found!" << std::endl;
        return;
    }
    std::shared_ptr<RigidBody> rigidBody = ecs.getElement<RigidBody>(0);
    if (rigidBody == nullptr) {
        std::cerr << "RigidBody component not found!" << std::endl;
        return;
    }
    std::shared_ptr<State> state = ecs.getElement<State>(0);
    if (state == nullptr) {
        std::cerr << "State component not found!" << std::endl;
        return;
    }

    buffer.overwrite(8 * 15, this->toVector(0), 8);
    std::string name = buffer.toStr(8, 8 * 16);

    std::size_t id = ecs.getAvailableSlot();
    ecs.addEntity(id, std::make_unique<Entity>());

    int nbPlayers = player->getEntities().size();
    int rangeSize = 5;

    pos->addEntity(id, ecs.getElement<Entity>(id, true));
    pos->setX(id, 20 + (nbPlayers / rangeSize) * 150);
    pos->setY(id, (nbPlayers % rangeSize) * 100);
    pos->setY(id, 1080/2 + pos->getY(id) * (nbPlayers % 2 ? 1 : -1));

    vel->addEntity(id, ecs.getElement<Entity>(id, true));
    vel->setSpeed(id, 0);
    vel->setDir(id, 0);

    player->addEntity(id, ecs.getElement<Entity>(id, true));
    player->setName(id, name);
    player->setScore(id, 0);
    player->setNbKills(id, 0);

    health->addEntity(id, ecs.getElement<Entity>(id, true));
    health->setHealth(id, 300);
    health->setMaxHealth(id, 300);
    health->setMinHealth(id, 0);

    rigidBody->addEntity(id, ecs.getElement<Entity>(id, true));
    rigidBody->setBody(id, sf::FloatRect(pos->getX(id), pos->getY(id), 100, 100));

    state->addEntity(id, ecs.getElement<Entity>(id, true));
    state->setState(id, StateType::ALIVE);

    ecs.addClient(id, ecs.getLastEndpoint());

    buffer.clear();
    buffer.reshape(24 / 8);
    buffer.overwrite(0, this->toVector(6), 8);
    buffer.overwrite(8, this->toVector(id), 16);
}
