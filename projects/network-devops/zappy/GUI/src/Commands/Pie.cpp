/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pie.cpp
*/

#include "../../include/Commands/Pie.hpp"

Pie::Pie()
{
}

Pie::~Pie()
{
}

void Pie::execute(Renderer &/*gui*/)
{
    if (getArgs().size() != 3) {
        return;
    }
    int x = std::stoi(getArgs().at(0));
    int y = std::stoi(getArgs().at(1));
    int incantation_res = std::stoi(getArgs().at(2));
}