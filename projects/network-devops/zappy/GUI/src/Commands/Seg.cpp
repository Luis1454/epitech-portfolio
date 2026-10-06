/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Seg.cpp
*/

#include "../../include/Commands/Seg.hpp"

Seg::Seg()
{
}

Seg::~Seg()
{
}

void Seg::execute(Renderer &gui)
{
    gui.setState("ENDGAME");
    if (getArgs().size() == 0)
        return;
    gui.getMap("default").setWinningTeam(getArgs().at(0));
}
