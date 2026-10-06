/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "System.hpp"
#include "../Components/Projectiles.hpp"
#include "../Components/RigidBody.hpp"
#include "../Components/Position.hpp"
#include "../Components/Health.hpp"
#include "../Components/State.hpp"
#include "../Components/Enemy.hpp"
#include <iostream>
#include <cmath>

class Collision : public System {
    public:
        Collision();
        ~Collision() = default;

        void update() override;

    protected:
    private:
};

#endif /* !COLLISION_HPP_ */
