/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Smg.cpp
*/

#include "../../include/Commands/Smg.hpp"

Smg::Smg()
{
}

Smg::~Smg()
{
}

void Smg::execute(Renderer &gui)
{
    if (getArgs().size() != 1) {
        return;
    }
    std::string message = getArgs().at(0);
}
