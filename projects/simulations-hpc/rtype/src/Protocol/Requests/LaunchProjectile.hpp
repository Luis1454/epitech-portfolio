/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** LaunchProjectile.hpp
*/

#ifndef CREATEENTITY_HPP_
#define CREATEENTITY_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"

template <typename T>
class LaunchProjectile: Request<T> {
    public:
        LaunchProjectile();
        ~LaunchProjectile() = default;

        void execute(Buffer<T> &buffer, ECS &ecs);
};

template class LaunchProjectile<uint64_t>;
template class LaunchProjectile<unsigned char>;
template class LaunchProjectile<int>;
template class LaunchProjectile<char>;

#endif /* !CREATEENTITY_HPP_ */