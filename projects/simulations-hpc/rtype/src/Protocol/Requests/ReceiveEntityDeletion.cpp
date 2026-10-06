/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveEntityDeletion
*/

#include "ReceiveEntityDeletion.hpp"

template <typename T>
ReceiveEntityDeletion<T>::ReceiveEntityDeletion() {
    this->_type = "ReceiveEntityDeletion";
}

template <typename T>
void ReceiveEntityDeletion<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    std::size_t id = buffer.toType(8, 16);
    ecs.dropEntity(id);
    buffer.clear();
    buffer.append(0);
}
