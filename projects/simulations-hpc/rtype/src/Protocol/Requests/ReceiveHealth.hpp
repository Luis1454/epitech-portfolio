/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveHealth
*/

#ifndef ReceiveHealth_HPP_
#define ReceiveHealth_HPP_

#include "Request.hpp"

template <typename T>
class ReceiveHealth : public Request<T> {
    public:
        ReceiveHealth();
        ~ReceiveHealth() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class ReceiveHealth<uint64_t>;
template class ReceiveHealth<Byte>;
template class ReceiveHealth<int>;
template class ReceiveHealth<char>;

#endif /* !ReceiveHealth_HPP_ */
