/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Sibur
*/

#include "../../include/Resources/Sibur.hpp"

Sibur::Sibur()
{
    _id = 5;
    _name = "sibur";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.25, 0.75};
}

Sibur::~Sibur()
{
}
