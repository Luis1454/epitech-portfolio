/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Thystame
*/

#include "../../include/Resources/Thystame.hpp"

Thystame::Thystame()
{
    _id = 6;
    _name = "thystame";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.75, 0.75};
}

Thystame::~Thystame()
{
}
