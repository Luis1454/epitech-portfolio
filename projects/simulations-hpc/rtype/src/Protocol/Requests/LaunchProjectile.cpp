/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** LaunchProjectile.cpp
*/

#include "LaunchProjectile.hpp"
#include "../../server/ECS/Components/Position.hpp"
#include "../../server/ECS/Components/Velocity.hpp"
#include "../../server/ECS/Components/Projectiles.hpp"
#include "../../server/ECS/Components/Player.hpp"
#include "../../server/ECS/Components/Enemy.hpp"

template <typename T>
LaunchProjectile<T>::LaunchProjectile()
{
    this->_type = "LaunchProjectile";
}

template <typename T>
void LaunchProjectile<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    buffer.overwrite(0, this->toVector(10), 8);
}
