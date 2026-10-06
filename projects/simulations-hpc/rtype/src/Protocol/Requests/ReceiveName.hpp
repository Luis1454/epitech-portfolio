/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ReceiveName
*/

#ifndef RECEIVENAME_HPP_
#define RECEIVENAME_HPP_

#include "Request.hpp"
#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"
// #include ""

template <typename T>
class ReceiveName : Request<T> {
    public:
        ReceiveName();
        ~ReceiveName() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;

    protected:
        std::size_t limitSize;
};

template class ReceiveName<uint64_t>;
template class ReceiveName<Byte>;
template class ReceiveName<int>;
template class ReceiveName<char>;

#endif /* !RECEIVENAME_HPP_ */
