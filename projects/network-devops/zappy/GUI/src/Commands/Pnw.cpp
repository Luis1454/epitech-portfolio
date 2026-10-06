/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pnw.cpp
*/

#include "../../include/Commands/Pnw.hpp"
#include "../../include/Commands/Ppo.hpp"

Pnw::Pnw()
{
}

Pnw::~Pnw()
{
}

void Pnw::execute(Renderer &gui)
{
    if (getArgs().size() != 6)
        return;
    int id = std::stoi(getArgs().at(0));
    int x = std::stoi(getArgs().at(1));
    int y = std::stoi(getArgs().at(2));
    int orientation = std::stoi(getArgs().at(3));
    int level = std::stoi(getArgs().at(4));
    std::shared_ptr<Team> team = gui.getMap("default").getTeam(getArgs().at(5));
    
    gui.getMap("default").addPlayer(Player(id, level, orientation, team, sf::Vector2f(x, y)));
}
