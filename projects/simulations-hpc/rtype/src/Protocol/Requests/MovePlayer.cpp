/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** MovePlayer
*/

#include "MovePlayer.hpp"

template<typename T>
MovePlayer<T>::MovePlayer()
{
    this->_type = "Move Player";
}

template <typename T>
void MovePlayer<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    long id = buffer.toType(8, 16);
    int size = 32 / 8;

    std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);

    if (vel == nullptr) {
        std::cerr << "Velocity component not found!" << std::endl;
        return;
    }

    float velX = vel->getSpeed(id) * std::cos(vel->getDir(id));
    float velY = vel->getSpeed(id) * std::sin(vel->getDir(id));

    buffer.clear();
    buffer.reshape(size);
    buffer.overwrite(0, MovePlayer<T>::toVector(12), 8);
    buffer.overwrite(8, this->toVector(id), 16);
    buffer.overwrite(16, this->toVector(velX), 8);
    buffer.overwrite(24, this->toVector(velY), 8);
}
