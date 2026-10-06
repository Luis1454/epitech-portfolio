/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** GetEntity.cpp
*/

#include "GetEntity.hpp"

template <typename T>
GetEntity<T>::GetEntity() {}

template <typename T>
void GetEntity<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    std::size_t id = buffer.toType(8, 16);

    std::shared_ptr<Projectiles> proj = ecs.getElement<Projectiles>(0);    
    std::shared_ptr<Position> pos = ecs.getElement<Position>(0);
    std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);
    std::shared_ptr<Player> player = ecs.getElement<Player>(0);
    std::shared_ptr<RigidBody> body = ecs.getElement<RigidBody>(0);
    std::shared_ptr<State> state = ecs.getElement<State>(0);

    std::map<std::string, std::shared_ptr<Component>> map = {
        {"Projectiles", proj},
        {"Position", pos},
        {"Velocity", vel},
        {"Player", player},
        {"RigidBody", body},
        {"Health", state}
    };

    for (auto &it : map)
        if (it.second == nullptr) {
            std::cerr << "Component " << it.first << " not found" << std::endl;
            return;
        }

    std::shared_ptr<Entity> entity = std::make_shared<Entity>();
    int newId = ecs.getAvailableSlot();

    ecs.addEntity(newId, entity);

    if (ecs.getClients().find(id) == ecs.getClients().end()) {
        std::cerr << "Client " << id << " not found" << std::endl;
        return;
    }

    std::shared_ptr<Entity> plyr = player->getEntity(id);

    if (plyr == nullptr) {
        std::cerr << "Entity " << id << " is not a player, cannot launch projectile" << std::endl;
        return;
    }

    proj->addEntity(newId, entity);
    pos->addEntity(newId, entity);
    vel->addEntity(newId, entity);
    body->addEntity(newId, entity);
    state->addEntity(newId, entity);

    state->setState(newId, StateType::UNDEFINED);
    proj->setName(newId, "Projectile");
    proj->setDamage(newId, 50);
    proj->setEmitter(newId, id);

    pos->setX(newId, pos->getX(id) + 100);
    pos->setY(newId, pos->getY(id));
    vel->set(newId, 10, 0);
    body->setBody(newId, sf::FloatRect(pos->getX(id) + 100, pos->getY(id), 100, 100));

    buffer.clear();
    buffer.append(0);
}
