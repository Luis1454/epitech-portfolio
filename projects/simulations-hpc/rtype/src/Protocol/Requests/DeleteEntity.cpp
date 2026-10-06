/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** DeleteEntity
*/

#include "DeleteEntity.hpp"

template <typename T>
DeleteEntity<T>::DeleteEntity() {
    this->_type = "DeleteEntity";
}

template <typename T>
void DeleteEntity<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    buffer.overwrite(0, this->toVector(14), 8);
}
