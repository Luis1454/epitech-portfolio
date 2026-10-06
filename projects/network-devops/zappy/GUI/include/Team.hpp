/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Team {
    public:
        Team(int id, std::string name);
        ~Team();
        std::string getName();
        void setName(std::string name);
        void updatePose();
        sf::IntRect getPose(std::string pose);
        void setId(int id);
        int getId();

    private:
        std::string _name;
        std::map<std::string, sf::IntRect> _poses;
        sf::Vector2i _pos;
        sf::Vector2i _spriteSize;
        int _clock;
        int _id;
};

#endif /* TEAM_HPP_ */
