/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** SendEntityPos
*/

#ifndef SendEntityPos_HPP_
#define SendEntityPos_HPP_

#include "Request.hpp"
#include "../../server/ECS/Components/Velocity.hpp"

template <typename T>
class SendEntityPos : public Request<T> {
    public:
        SendEntityPos() = default;
        ~SendEntityPos() = default;

        void setPos(std::vector<float> pos);

        std::vector<float> getPos() const;

        void execute(Buffer<T> &buffer, ECS &ecs) override;

    protected:
        std::vector<float> _pos;
};

template class SendEntityPos<uint64_t>;
template class SendEntityPos<char>;
template class SendEntityPos<Byte>;
template class SendEntityPos<int>;

#endif /* !SendEntityPos_HPP_ */
