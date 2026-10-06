/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pex.cpp
*/

#include "../../include/Commands/Pex.hpp"

Pex::Pex()
{
}

Pex::~Pex()
{
}

void Pex::execute(Renderer &gui)
{
    if (getArgs().size() != 1)
        return;
    int id = std::stoi(getArgs().at(0));
    gui.getMap("default").expulsePlayer(id);
}