/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pic.cpp
*/

#include "../../include/Commands/Pic.hpp"

Pic::Pic()
{
}

Pic::~Pic()
{
}

void Pic::execute(Renderer &/*gui*/)
{
    if (getArgs().size() != 4) {
        return;
    }
    int x = std::stoi(getArgs().at(0));
    int y = std::stoi(getArgs().at(1));
    int level = std::stoi(getArgs().at(2));
    int playerIncantation = std::stoi(getArgs().at(3));
}