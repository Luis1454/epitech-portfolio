/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Mendiane
*/

#include "../../include/Resources/Mendiane.hpp"

Mendiane::Mendiane()
{
    _id = 3;
    _name = "mendiane";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.25, 0.5};
}

Mendiane::~Mendiane()
{
}
