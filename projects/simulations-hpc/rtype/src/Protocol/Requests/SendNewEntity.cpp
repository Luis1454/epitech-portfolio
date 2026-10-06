/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** SendNewEntity.cpp
*/

#include "SendNewEntity.hpp"
#include "../../server/ECS/Entities/Entity.hpp"
#include "../../server/ECS/Components/Enemy.hpp"
#include "../../server/ECS/Components/Position.hpp"
#include "../../server/ECS/Components/Velocity.hpp"
#include "../../server/ECS/Components/Health.hpp"
#include "../../server/ECS/Components/Boss.hpp"

template <typename T>
SendNewEntity<T>::SendNewEntity() {
    this->_type = "SendNewEntity";
}

template <typename T>
void SendNewEntity<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    std::vector<int> types;

    if (buffer.size() < 2) {
        std::cerr << "SendNewEntity : Initial data not found (buffer too small)" << std::endl;
        return;
    }

    buffer.reshape(64);
    std::size_t id = buffer.toType(8, 16);
    buffer.overwrite(0, this->toVector(8), 8);
    std::shared_ptr<Entity> entity = ecs.getElement<Entity>(id, true);
    std::shared_ptr<State> state = ecs.getElement<State>(0);

    if (entity == nullptr || state == nullptr) {
        if (entity == nullptr)
            std::cout << "Entity not found (id " << id << ")" << std::endl;
        else
            std::cout << "Element State not found" << std::endl;
        buffer.clear();
        buffer.append(0);
        return;
    }

    if (ecs.getElement<Player>(0) != nullptr && ecs.getElement<Player>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Player);

    if (ecs.getElement<Boss>(0) != nullptr && ecs.getElement<Boss>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Boss);

    if (ecs.getElement<Enemy>(0) != nullptr && ecs.getElement<Enemy>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Enemy);

    if (ecs.getElement<Position>(0) != nullptr && ecs.getElement<Position>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Position);

    if (ecs.getElement<Velocity>(0) != nullptr && ecs.getElement<Velocity>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Velocity);

    if (ecs.getElement<Health>(0) != nullptr && ecs.getElement<Health>(0)->getEntity(id) != nullptr)
        types.push_back(ComponentType::e_Health);

    if (ecs.getElement<Projectiles>(0) != nullptr && ecs.getElement<Projectiles>(0)->getEntity(id) != nullptr) {
        types.push_back(ComponentType::e_Projectile);

        if (state->getEntity(id) != nullptr)
            state->setState(id, StateType::INVINCIBLE);
    }

    for (int i = 0; i < types.size(); i++)
        buffer.overwrite(24 + i * 8, this->toVector(types[i]), 8);
    buffer.overwrite(24 + types.size() * 8, this->toVector(0), 8);

}
