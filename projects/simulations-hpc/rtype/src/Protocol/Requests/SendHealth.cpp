/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** SendHealth
*/

#include "SendHealth.hpp"

template <typename T>
SendHealth<T>::SendHealth() {
    this->_type = "SendHealth";
}

template <typename T>
void SendHealth<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    long long id = buffer.toType(8, 16);
    std::shared_ptr<Health> health = ecs.getElement<Health>(0);

    if (health == nullptr) {
        std::cout << "Health not found" << std::endl;
        return;
    }

    buffer.overwrite(0, this->toVector(16), 8);

    buffer.overwrite(24, this->toVector(health->getMinHealth(id)), 32);
    buffer.overwrite(24+32, this->toVector(health->getMaxHealth(id)), 32);
    buffer.overwrite(24+64, this->toVector(health->getHealth(id)), 32);
}
