/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Plv.cpp
*/

#include "../../include/Commands/Plv.hpp"

Plv::Plv()
{
}

Plv::~Plv()
{
}

void Plv::execute(Renderer &gui)
{
    if (getArgs().size() != 2)
        return;
    int id = std::stoi(getArgs().at(0));
    int level = std::stoi(getArgs().at(1));

    gui.getMap("default").setPlayerLevel(id, level);
}
