/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "Inventory.hpp"
#include "Team.hpp"
#include <iostream>

class Player {
    public:
        Player();
        Player(int id, int level, int orientation, std::shared_ptr<Team> team, sf::Vector2f position);
        ~Player();

        void setId(int id);
        void setLevel(int level);
        void setOrientation(int orientation);
        void setInventory(Inventory inventory);
        void setPosition(sf::Vector2f position);

        int getId();
        int getLevel();
        int getOrientation();

        Inventory getInventory();
        sf::Vector2f getPosition();
        std::shared_ptr<Team> getTeam();
        void setTeam(std::shared_ptr<Team> team);

    private:
        int _id;
        int _level;
        int _orientation;

        sf::Vector2f _position;

        Inventory _inventory;

        sf::Texture _texture;
        sf::Sprite _sprite;
        std::shared_ptr<Team> _team;
};

#endif /* !PLAYER_HPP_ */
