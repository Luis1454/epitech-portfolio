/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pdr.cpp
*/

#include "../../include/Commands/Pdr.hpp"

Pdr::Pdr()
{
}

Pdr::~Pdr()
{
}

void Pdr::execute(Renderer &gui)
{
    if (getArgs().size() != 2)
        return;
    int id = std::stoi(getArgs().at(0));
    int res = std::stoi(getArgs().at(1));
    
}