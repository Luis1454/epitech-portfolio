/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Gravity
*/

#ifndef GRAVITY_HPP_
#define GRAVITY_HPP_

#include "System.hpp"

class Gravity : public System {
    public:
        Gravity();
        ~Gravity() = default;

        void update() override;

    protected:
        const float _g = 9.81f / 1000.0f;
};

#endif /* !GRAVITY_HPP_ */
