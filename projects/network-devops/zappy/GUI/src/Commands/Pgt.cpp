/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pgt.cpp
*/

#include "../../include/Commands/Pgt.hpp"

Pgt::Pgt()
{
}

Pgt::~Pgt()
{
}

void Pgt::execute(Renderer &gui)
{
    if (getArgs().size() != 2)
        return;
    int id = std::stoi(getArgs().at(0));
    int res = std::stoi(getArgs().at(1));
}
