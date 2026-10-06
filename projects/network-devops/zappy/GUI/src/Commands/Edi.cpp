/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Edi.cpp
*/

#include "../../include/Commands/Edi.hpp"

Edi::Edi()
{
}

Edi::~Edi()
{
}

void Edi::execute(Renderer &gui)
{
    if (getArgs().size() != 1)
        return;
    gui.getMap("default").dropEgg(std::stoi(getArgs().at(0)));
}
