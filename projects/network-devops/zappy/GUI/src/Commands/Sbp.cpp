/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Sbp.cpp
*/

#include "../../include/Commands/Sbp.hpp"

Sbp::Sbp()
{
}

Sbp::~Sbp()
{
}

void Sbp::execute(Renderer &gui)
{
    if (getArgs().size() != 0)
        return;
    (void)gui;
}
