/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Linemate
*/

#include "../../include/Resources/Linemate.hpp"

Linemate::Linemate()
{
    _id = 2;
    _name = "linemate";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.75, 0.25};
}

Linemate::~Linemate()
{
}
