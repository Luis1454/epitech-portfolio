/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ReceiveEntityPos
*/

#include "ReceiveEntityPos.hpp"

template <typename T>
void ReceiveEntityPos<T>::setPos(std::vector<float> pos)
{
    _pos = pos;
}

template <typename T>
std::vector<float> ReceiveEntityPos<T>::getPos() const
{
    return _pos;
}

template <typename T>
void ReceiveEntityPos<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    int end = buffer.size() * sizeof(T) * 8;

    long long id = buffer.toType(8, 16);
    long long posX = buffer.toType(8+16, 16);
    long long posY = buffer.toType(8+16+16, 16); // 32 bits
    long long dir = buffer.toType(8+16+16+16, 8); // 8 bits
    long long speed = buffer.toType(8+16+16+16+8, 8); // 8 bits

    auto entityPosition = ecs.getElement<Position>(0);

    if (entityPosition != nullptr) {
        entityPosition->setX(id, posX);
        entityPosition->setY(id, posY);
    }

    auto entityVelocity = ecs.getElement<Velocity>(0);
    if (entityVelocity != nullptr) {
        entityVelocity->setSpeed(id, speed);
        entityVelocity->setDir(id, dir);
    }
    buffer.clear();
}
