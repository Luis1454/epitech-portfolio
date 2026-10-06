/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Component.hpp"

class Player : public Component {
    public:
        Player() = default;
        ~Player() override = default;

        void info() const override;
        void dropEntity(int idx) override;

        void setName(std::size_t idx, const std::string &name);
        std::string getName(std::size_t idx) const;

        void setScore(std::size_t idx, int score);
        void addScore(std::size_t idx, int score);
        int getScore(std::size_t idx) const;

        void setNbKills(std::size_t idx, int nb);
        void addNbKills(std::size_t idx, int nb);
        int getNbKills(std::size_t idx) const;
        void addKill(std::size_t idx);

    protected:
        std::unordered_map<std::size_t, std::string> _names;
        std::unordered_map<std::size_t, int> _scores;
        std::unordered_map<std::size_t, int> _nbKills;

};

#endif /* !PLAYER_HPP_ */
