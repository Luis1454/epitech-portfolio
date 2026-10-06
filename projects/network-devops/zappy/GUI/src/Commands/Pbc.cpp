/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pbc.cpp
*/

#include "../../include/Commands/Pbc.hpp"

Pbc::Pbc()
{
}

Pbc::~Pbc()
{
}

void Pbc::execute(Renderer &gui)
{
    if (getArgs().size() != 2)
        return;
    int player_id = std::stoi(getArgs().at(0));
    std::string message = std::stoi(getArgs().at(1));
}
