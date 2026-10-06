/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Phiras
*/

#include "../../include/Resources/Phiras.hpp"

Phiras::Phiras()
{
    _id = 4;
    _name = "phiras";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.75, 0.5};
}

Phiras::~Phiras()
{
}
