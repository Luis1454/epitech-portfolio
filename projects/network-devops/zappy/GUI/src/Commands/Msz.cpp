/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Msz.cpp
*/

#include "../../include/Commands/Msz.hpp"

Msz::Msz()
{
}

Msz::~Msz()
{
}

void Msz::execute(Renderer &gui)
{
    if (getArgs().size() != 2)
        return;
    int x = std::stoi(getArgs().at(0));
    int y = std::stoi(getArgs().at(1));

    gui.getMap("default").setShape(x, y);
}
