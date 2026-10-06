/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceivePlayerMove
*/

#ifndef RECEIVEPLAYERMOVE_HPP_
#define RECEIVEPLAYERMOVE_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"
#include "../../server/ECS/Components/Velocity.hpp"

template <typename T>
class ReceivePlayerMove : public Request<T> {
    public:
        ReceivePlayerMove();
        ~ReceivePlayerMove() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class ReceivePlayerMove<uint64_t>;
template class ReceivePlayerMove<unsigned char>;
template class ReceivePlayerMove<int>;
template class ReceivePlayerMove<char>;

#endif /* !RECEIVEPLAYERMOVE_HPP_ */
