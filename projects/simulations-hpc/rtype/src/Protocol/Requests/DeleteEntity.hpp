/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** DeleteEntity
*/

#ifndef DELETEENTITY_HPP_
#define DELETEENTITY_HPP_

#include "Request.hpp"

template <typename T>
class DeleteEntity : public Request<T> {
    public:
        DeleteEntity();
        ~DeleteEntity() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class DeleteEntity<uint64_t>;
template class DeleteEntity<Byte>;
template class DeleteEntity<int>;
template class DeleteEntity<char>;

#endif /* !DELETEENTITY_HPP_ */
