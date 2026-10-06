/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** MovePlayer
*/

#ifndef MOVEPLAYER_HPP_
#define MOVEPLAYER_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"

template <typename T>
class MovePlayer : public Request<T> {
    public:
        MovePlayer();
        ~MovePlayer() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class MovePlayer<uint64_t>;
template class MovePlayer<unsigned char>;
template class MovePlayer<int>;
template class MovePlayer<char>;

#endif /* !MOVEPLAYER_HPP_ */
