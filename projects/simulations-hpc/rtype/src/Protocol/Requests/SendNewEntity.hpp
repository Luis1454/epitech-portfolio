/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** SendNewEntity.hpp
*/

#ifndef SENDNEWENTITY_HPP_
#define SENDNEWENTITY_HPP_

#include <string>
#include "Request.hpp"

template <typename T>
class SendNewEntity : public Request<T> {
public:
    SendNewEntity();
    ~SendNewEntity() = default;
    void execute(Buffer<T> &buffer, ECS &ecs) override;

};
template class SendNewEntity<uint64_t>;
template class SendNewEntity<char>;
template class SendNewEntity<Byte>;
template class SendNewEntity<int>;

#endif /* !SENDNEWENTITY_HPP_ */