/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveGameEvent
*/

#ifndef ReceiveGameEvent_HPP_
#define ReceiveGameEvent_HPP_

#include "Request.hpp"
#include "../../client/Components/EventMessage.hpp"
#include "../../Protocol/Requests/SendGameEvent.hpp"

template <typename T>
class ReceiveGameEvent : public Request<T> {
    public:
        ReceiveGameEvent();
        ~ReceiveGameEvent() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class ReceiveGameEvent<uint64_t>;
template class ReceiveGameEvent<Byte>;
template class ReceiveGameEvent<int>;
template class ReceiveGameEvent<char>;

#endif /* !ReceiveGameEvent_HPP_ */
