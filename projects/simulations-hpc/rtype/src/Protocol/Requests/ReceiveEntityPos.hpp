/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ReceiveEntityPos
*/

#ifndef ReceiveEntityPos_HPP_
#define ReceiveEntityPos_HPP_

#include "Request.hpp"
#include "../../server/ECS/Components/Velocity.hpp"

template <typename T>
class ReceiveEntityPos : public Request<T> {
    public:
        ReceiveEntityPos() = default;
        ~ReceiveEntityPos() = default;

        void setPos(std::vector<float> pos);

        std::vector<float> getPos() const;

        void execute(Buffer<T> &buffer, ECS &ecs) override;

    protected:
        std::vector<float> _pos;
};

template class ReceiveEntityPos<uint64_t>;
template class ReceiveEntityPos<char>;
template class ReceiveEntityPos<Byte>;
template class ReceiveEntityPos<int>;

#endif /* !ReceiveEntityPos_HPP_ */
