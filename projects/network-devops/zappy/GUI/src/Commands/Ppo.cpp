/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Ppo.cpp
*/

#include "../../include/Commands/Ppo.hpp"

Ppo::Ppo()
{
}

Ppo::~Ppo()
{
}

void Ppo::execute(Renderer &gui)
{
    if (getArgs().size() != 4)
        return;
    int id = std::stoi(getArgs().at(0));
    int x = std::stoi(getArgs().at(1));
    int y = std::stoi(getArgs().at(2));
    int orientation = std::stoi(getArgs().at(3));
    gui.getMap("default").setPlayerPosition(id, sf::Vector2f(x, y));
    gui.getMap("default").setPlayerOrientation(id, orientation);
}
