/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Motion
*/

#include "Motion.hpp"
#include <cmath>
#include "../Components/Position.hpp"
#include "../Components/Velocity.hpp"

Motion::Motion() {
    this->_name = "Motion";
}

void Motion::update() {
    std::unordered_map<int, std::pair<float, float>> moves;

    // Étape 1 : Filtrer et traiter les Velocity
    for (const auto &component : _components) {
        auto velocity = std::dynamic_pointer_cast<Velocity>(component.second);
        if (velocity)
            for (const auto &id : velocity->getIDs())
                moves[id] = {
                    moves[id].first + velocity->getSpeed(id) * _dt * std::cos(velocity->getDir(id)),
                    moves[id].second + velocity->getSpeed(id) * _dt * std::sin(velocity->getDir(id))
                };
    }

    // Étape 2 : Filtrer et traiter les Position
    for (const auto &component : _components) {
        auto position = std::dynamic_pointer_cast<Position>(component.second);
        if (position)
            for (const auto &id : position->getIDs())
                if (moves.count(id))
                    position->add(id, {moves[id].first * _dt * 2000, moves[id].second * _dt * 2000});
    }
}
