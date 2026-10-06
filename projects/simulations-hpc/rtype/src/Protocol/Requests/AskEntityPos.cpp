/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** AskEntityPos
*/

#include "AskEntityPos.hpp"

template<typename T>
AskEntityPos<T>::AskEntityPos() {
    this->_type = "Ask Entity Pos";
}

template <typename T>
void AskEntityPos<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    long data = 0;
    long id = buffer.toType(8, 16);
    int size = 24 / 8;

    buffer.clear();
    buffer.reshape(size);
    buffer.overwrite(0, AskEntityPos<T>::toVector(4), 8);
    buffer.overwrite(8, this->toVector(id), 16);
}

template class Request<uint64_t>;
template class Request<unsigned char>;
template class Request<int>;
template class Request<char>;
