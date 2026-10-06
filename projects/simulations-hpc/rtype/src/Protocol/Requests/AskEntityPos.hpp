/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** AskEntityPos
*/

#ifndef ASKENTITYPOS_HPP_
#define ASKENTITYPOS_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"

template <typename T>
class AskEntityPos : Request<T> {
    public:
        AskEntityPos();
        ~AskEntityPos() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class AskEntityPos<uint64_t>;
template class AskEntityPos<Byte>;
template class AskEntityPos<int>;
template class AskEntityPos<char>;

#endif /* !ASKENTITYPOS_HPP_ */
