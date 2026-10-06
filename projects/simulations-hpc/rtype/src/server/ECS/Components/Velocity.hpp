/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "Component.hpp"

typedef struct vel_s {
    float speed;
    float dir;
} vel_t;

class Velocity : public Component {
    public:
        Velocity() = default;
        ~Velocity() override = default;

        void info() const override;
        void dropEntity(int idx) override;

        void setSpeed(std::size_t idx, float speed);
        void setDir(std::size_t idx, float dir);
        void set(std::size_t idx, float speed, float dir);

        float getSpeed(std::size_t idx);
        float getDir(std::size_t idx);
        std::pair<float, float> get(std::size_t idx);

    protected:
        std::unordered_map<std::size_t, vel_t> _vel;
};

#endif /* !VELOCITY_HPP_ */
