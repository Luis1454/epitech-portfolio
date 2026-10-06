/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Gravity System
*/

#include "Gravity.hpp"
#include "../Components/Velocity.hpp"
#include <iostream>

Gravity::Gravity()
{
    this->_name = "Gravity";
}

void Gravity::update()
{
    for (const auto& component : _components) {
        auto velocity = std::dynamic_pointer_cast<Velocity>(component.second);
        if (velocity)
            for (const auto &id : velocity->getIDs())
                velocity->setSpeed(id, velocity->getSpeed(id) + _g);
    }
}
