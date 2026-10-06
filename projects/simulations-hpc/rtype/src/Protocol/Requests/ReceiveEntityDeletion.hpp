/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveEntityDeletion
*/

#ifndef RECEIVEENTITYDELETION_HPP_
#define RECEIVEENTITYDELETION_HPP_

#include "Request.hpp"

template <typename T>
class ReceiveEntityDeletion : public Request<T> {
    public:
        ReceiveEntityDeletion();
        ~ReceiveEntityDeletion() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class ReceiveEntityDeletion<uint64_t>;
template class ReceiveEntityDeletion<unsigned char>;
template class ReceiveEntityDeletion<int>;
template class ReceiveEntityDeletion<char>;

#endif /* !RECEIVEENTITYDELETION_HPP_ */
