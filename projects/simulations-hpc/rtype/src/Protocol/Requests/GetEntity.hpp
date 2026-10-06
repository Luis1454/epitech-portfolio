/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** GetEntity.hpp
*/

#ifndef GETENTITY_HPP_
#define GETENTITY_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"

template <typename T>
class GetEntity : Request<T>
{
public:
    GetEntity();
    ~GetEntity() = default;

    void execute(Buffer<T> &buffer, ECS &ecs);

private:
};

template class GetEntity<uint64_t>;
template class GetEntity<unsigned char>;
template class GetEntity<int>;
template class GetEntity<char>;

#endif /* !GETENTITY_HPP_ */