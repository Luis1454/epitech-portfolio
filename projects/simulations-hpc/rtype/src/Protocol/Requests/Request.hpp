/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Request
*/

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include "../../server/ECS/ECS.hpp"
#include "../Buffer/Buffer.hpp"

#include "../../server/ECS/Components/Position.hpp"
#include "../../server/ECS/Components/Player.hpp"
#include "../../server/ECS/Components/Enemy.hpp"
#include "../../server/ECS/Components/Projectiles.hpp"
#include "../../server/ECS/Components/Velocity.hpp"
#include "../../server/ECS/Components/RigidBody.hpp"
#include "../../server/ECS/Components/Health.hpp"
#include "../../server/ECS/Components/State.hpp"
#include "../../client/Components/Sprite.hpp"

#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <type_traits>

template <typename T>
class Request {
public:
    Request() = default;
    ~Request() = default;

    std::string getType() const;
    virtual void execute(Buffer<T> &buffer, ECS &ecs) = 0;

protected:
    std::string _type = "undefined";

    template <typename N>
    std::vector<T> toVector(const N n);
};

#endif /* REQUEST_HPP_ */
