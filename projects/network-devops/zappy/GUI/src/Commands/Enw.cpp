/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Enw.cpp
*/

#include "../../include/Commands/Enw.hpp"
#include "../../include/Egg.hpp"

Enw::Enw()
{
}

Enw::~Enw()
{
}

void Enw::execute(Renderer &gui)
{
    if (getArgs().size() != 4)
        return;

    int eggId = std::stoi(getArgs().at(0));
    int playerId = std::stoi(getArgs().at(1));
    int x = std::stoi(getArgs().at(2));
    int y = std::stoi(getArgs().at(3));
    gui.getMap("default").setEgg(Egg(eggId, playerId, sf::Vector2i(x, y), std::make_shared<sf::Sprite>(gui.getEggSprite("default"))));
}
