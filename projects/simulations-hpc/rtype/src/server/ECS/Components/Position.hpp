/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "Component.hpp"

typedef struct pos_s {
    float x;
    float y;
} pos_t;

class Position : public Component {
    public:
        Position() = default;
        ~Position() override = default;

        void info() const override;
        void dropEntity(int idx) override;

        void setX(std::size_t idx, float x);
        void setY(std::size_t idx, float y);
        void set(std::size_t idx, pos_t pos);

        void add(std::size_t idx, pos_t speed);

        float getX(std::size_t idx);
        float getY(std::size_t idx);

    protected:
        std::unordered_map<std::size_t, pos_t> _pos;
};

#endif /* !POSITION_HPP_ */
