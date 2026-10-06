/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveNewEntity
*/

#ifndef RECEIVENEWENTITY_HPP_
#define RECEIVENEWENTITY_HPP_

#include "ReceiveName.hpp"
#include "../../server/ECS/Components/Player.hpp"
#include "../../server/ECS/Components/Velocity.hpp"

template<typename T>
class ReceiveNewEntity : public Request<T> {
    public:
        ReceiveNewEntity();
        ~ReceiveNewEntity();

        void execute(Buffer<T> &buffer, ECS &ecs) override;

    protected:
    private:
};

template class ReceiveNewEntity<uint64_t>;
template class ReceiveNewEntity<Byte>;
template class ReceiveNewEntity<int>;
template class ReceiveNewEntity<char>;

#endif /* !RECEIVENEWENTITY_HPP_ */
