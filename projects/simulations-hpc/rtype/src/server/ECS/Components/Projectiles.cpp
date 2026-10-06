/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Projectiles.cpp
*/


#include "Projectiles.hpp"

void Projectiles::info() const {
    std::cout << "Projectiles (" << _names.size() << ")" << std::endl;
    for (auto &elem : _names)
        std::cout << "Projectiles #" << elem.first << " : " << elem.second << std::endl;
}

void Projectiles::dropEntity(int idx) {
    Component::dropEntity(idx);

    _names.erase(idx);
    _damages.erase(idx);
}

void Projectiles::setName(std::size_t idx, const std::string &name) {
    _names.insert_or_assign(idx, name);
}

std::string Projectiles::getName(std::size_t idx) const {
    if (_names.find(idx) != _names.end())
        return _names.at(idx);
    return std::string("");
}

void Projectiles::setDamage(std::size_t idx, float damage) {
    _damages.insert_or_assign(idx, damage);
}

float Projectiles::getDamage(std::size_t idx) {
    if (_damages.find(idx) == _damages.end())
        return 0;
    return _damages.at(idx);
}

void Projectiles::setEmitter(std::size_t idx, std::size_t emitter) {
    _emitters.insert_or_assign(idx, emitter);
}

std::size_t Projectiles::getEmitter(std::size_t idx) {
    if (_emitters.find(idx) == _emitters.end())
        return 0;
    return _emitters.at(idx);
}
