/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Boss
*/

#ifndef BOSS_HPP_
#define BOSS_HPP_

#include "Enemy.hpp"

class Boss : public Component {
    public:
        Boss() = default;
        ~Boss() = default;

        void dropEntity(int idx) override;
        void info() const override;
};

#endif /* !BOSS_HPP_ */
