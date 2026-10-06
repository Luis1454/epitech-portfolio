/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** SendEntityPos
*/

#include "SendEntityPos.hpp"

template <typename T>
void SendEntityPos<T>::setPos(std::vector<float> pos)
{
    _pos = pos;
}

template <typename T>
std::vector<float> SendEntityPos<T>::getPos() const
{
    return _pos;
}

template <typename T>
void SendEntityPos<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    long long id = buffer.toType(8, 16);


    std::shared_ptr<Position> pos = ecs.getElement<Position>(0);
    if (pos == nullptr) {
        std::cout << "Position not found" << std::endl;
        return;
    }

    std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);
    if (vel == nullptr) {
        std::cout << "Velocity not found" << std::endl;
        return;
    }

    if (pos->getEntity(id) == nullptr)
        return;

    if (vel->getEntity(id) == nullptr) {
        std::cout << "Velocity not found" << std::endl;
        return;
    }

    buffer.overwrite(0, this->toVector(5), 8);

    unsigned int posX = pos->getX(id);
    buffer.overwrite(8+16, this->toVector(posX), 16);

    unsigned int posY = pos->getY(id);
    buffer.overwrite(8+16+16, this->toVector(posY), 16);

    unsigned int dir = vel->getDir(id);
    buffer.overwrite(8+16+16+16, this->toVector(dir), 8);

    unsigned int speed = vel->getSpeed(id);
    buffer.overwrite(8+16+16+16+8, this->toVector(speed), 8);

    if (buffer.toType(8, 16) == 65535) {
        buffer.clear();
        buffer.append(0);
    }
}
