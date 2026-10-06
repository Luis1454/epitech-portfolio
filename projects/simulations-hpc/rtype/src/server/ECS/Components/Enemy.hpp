/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Component.hpp"
#include "Player.hpp"

class Enemy : public Component {
    public:
        Enemy() = default;
        ~Enemy() override = default;

        void dropEntity(int idx) override;
        void info() const override;
        void setNbKilled(std::size_t nb);
        void setNbSpawned(std::size_t nb);

        void addKill();
        void addSpawn();

        std::size_t getNbKilled() const;
        std::size_t getNbSpawned() const;

    private:
        std::size_t _nbKilled = 0;
        std::size_t _nbSpawned = 0;
};

#endif /* !ENEMY_HPP_ */
