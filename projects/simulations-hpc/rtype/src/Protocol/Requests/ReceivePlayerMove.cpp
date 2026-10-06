/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceivePlayerMove
*/

#include "ReceivePlayerMove.hpp"

template<typename T>
ReceivePlayerMove<T>::ReceivePlayerMove()
{
    this->_type = "Receive Player Move";
}

template <typename T>
void ReceivePlayerMove<T>::execute(Buffer<T> &buffer, ECS &ecs)
{
    long id = buffer.toType(8, 16);
    int size = 32 / 8;

    std::shared_ptr<Velocity> vel = ecs.getElement<Velocity>(0);

    if (vel == nullptr) {
        std::cerr << "Velocity component not found!" << std::endl;
        return;
    }

    float PI = 3.141592653f;

    const std::map<int, float> dirs = {
        {1, PI / 2 * 3},
        {2, PI / 2},
        {3, PI},
        {4, 0.0f}
    };

    std::size_t val = buffer.toType(24, 8);

    if (1 <= val && val <= 4) {
        vel->setSpeed(id, 10.0f);
        vel->setDir(id, dirs.at(val));
    } else if (!val)
        vel->setSpeed(id, 0.0f);

    buffer.clear();
    buffer.append(0);
}
