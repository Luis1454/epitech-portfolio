/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Tna.cpp
*/

#include "../../include/Commands/Tna.hpp"

Tna::Tna()
{
}

Tna::~Tna()
{
}

void Tna::execute(Renderer &gui)
{
    if (getArgs().size() == 1)
        gui.getMap("default").setTeam(getArgs().at(0));
}
