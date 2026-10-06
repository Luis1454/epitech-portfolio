/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Ebo.cpp
*/

#include "../../include/Commands/Ebo.hpp"

Ebo::Ebo()
{
}

Ebo::~Ebo()
{
}

void Ebo::execute(Renderer &gui)
{
    if (getArgs().size() != 1)
        return;
    gui.getMap("default").dropEgg(std::stoi(getArgs().at(0)));
}
