/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Enemy
*/

#include "Enemy.hpp"

void Enemy::info() const {
    std::cout << "There is " << _entities.size() << " enemies" << std::endl;
    for (const auto &entity : _entities)
        std::cout << "- Enemy #" << entity.first << std::endl;
}

void Enemy::dropEntity(int id) {
    Component::dropEntity(id);
}

void Enemy::setNbKilled(std::size_t nb) {
    _nbKilled = nb;
}

void Enemy::addKill() {
    _nbKilled++;
}

void Enemy::setNbSpawned(std::size_t nb) {
    _nbSpawned = nb;
}

void Enemy::addSpawn() {
    _nbSpawned++;
}

std::size_t Enemy::getNbKilled() const {
    return _nbKilled;
}

std::size_t Enemy::getNbSpawned() const {
    return _nbSpawned;
}
