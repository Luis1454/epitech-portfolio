/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** health
*/

#include "Health.hpp"

void Health::info() const {
    std::cout << "Healths (" << _healths.size() << "):" << std::endl;
    for (auto &health : _healths)
        std::cout << "  " << health.first << " -> " << health.second << std::endl;
}

void Health::dropEntity(int idx) {
    Component::dropEntity(idx);

    _healths.erase(idx);
    _maxHealths.erase(idx);
    _minHealths.erase(idx);
}

void Health::setHealth(std::size_t id, int health) {
    _healths.insert_or_assign(id, health);
}

void Health::removeHealth(std::size_t id) {
    _healths.erase(id);
}

int Health::getHealth(std::size_t id) const {
    if (_healths.find(id) == _healths.end())
        return 0;
    return _healths.at(id);
}

int Health::getMaxHealth(std::size_t id) const {
    if (_maxHealths.find(id) == _maxHealths.end())
        return 0;
    return _maxHealths.at(id);
}

int Health::getMinHealth(std::size_t id) const {
    if (_minHealths.find(id) == _minHealths.end())
        return 0;
    return _minHealths.at(id);
}

void Health::setMaxHealth(std::size_t id, int maxHealth) {
    _maxHealths[id] = maxHealth;
}

void Health::setMinHealth(std::size_t id, int minHealth) {
    _minHealths[id] = minHealth;
}

void Health::takeDamages(std::size_t id, int damages) {
    _healths[id] -= damages;
    if (_healths[id] < _minHealths[id])
        _healths[id] = _minHealths[id];
}
