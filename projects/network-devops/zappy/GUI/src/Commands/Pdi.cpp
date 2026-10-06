/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pdi.cpp
*/

#include "../../include/Commands/Pdi.hpp"

Pdi::Pdi()
{
}

Pdi::~Pdi()
{
}

void Pdi::execute(Renderer &gui)
{
    if (getArgs().size() != 1)
        return;
    int id = std::stoi(getArgs().at(0));

    gui.getMap("default").dropPlayer(id);
}
