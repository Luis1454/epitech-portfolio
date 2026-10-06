/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Deraumere
*/

#include "../../include/Resources/Deraumere.hpp"

Deraumere::Deraumere()
{
    _id = 1;
    _name = "deraumere";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.25, 0.25};
}

Deraumere::~Deraumere()
{
}
