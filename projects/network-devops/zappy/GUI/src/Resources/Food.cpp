/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Food
*/

#include "../../include/Resources/Food.hpp"

Food::Food()
{
    _id = 0;
    _name = "food";
    _spriteCoord = {_id * _spriteSize.x, 0};
    _offset = {0.5, 0.25};
}

Food::~Food()
{
}
