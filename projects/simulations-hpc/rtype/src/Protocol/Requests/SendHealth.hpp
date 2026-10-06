/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** SendHealth
*/

#ifndef SENDHEALTH_HPP_
#define SENDHEALTH_HPP_

#include "Request.hpp"

template <typename T>
class SendHealth : public Request<T> {
    public:
        SendHealth();
        ~SendHealth() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class SendHealth<uint64_t>;
template class SendHealth<Byte>;
template class SendHealth<int>;
template class SendHealth<char>;

#endif /* !SENDHEALTH_HPP_ */
