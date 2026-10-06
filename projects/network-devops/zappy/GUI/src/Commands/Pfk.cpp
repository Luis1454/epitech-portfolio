/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pfk.cpp
*/

#include "../../include/Commands/Pfk.hpp"

Pfk::Pfk()
{
}

Pfk::~Pfk()
{
}

void Pfk::execute(Renderer &gui)
{
    if (getArgs().size() != 1)
        return;
    int id = std::stoi(getArgs().at(0));
    gui.getMap("default").forkPlayer(id);
}
