/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveHealth
*/

#include "ReceiveHealth.hpp"

template <typename T>
ReceiveHealth<T>::ReceiveHealth() {
    this->_type = "ReceiveHealth";
}

template <typename T>
void ReceiveHealth<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    long long id = buffer.toType(8, 16);
    std::shared_ptr<Health> health = ecs.getElement<Health>(0);

    if (health == nullptr) {
        std::cout << "Position not found" << std::endl;
        return;
    }

    long long min = buffer.toType(24, 32);
    long long max = buffer.toType(24+32, 32);
    long long HP = buffer.toType(24+64, 32);

    health->setMinHealth(id, min);
    health->setMaxHealth(id, max);
    health->setHealth(id, HP);

    buffer.clear();
    buffer.append(0);
}
