/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Team
*/

#include "../../include/Team.hpp"
#include <iostream>

Team::Team(int id, std::string name)
{
    _spriteSize = {32, 48};
    _name = name;
    _clock = 0;
    setId(id);
}

Team::~Team()
{
}

void Team::updatePose()
{
    int y = 0;

    for (auto &dir : std::vector<std::string>{"down", "left", "right", "up"})
        _poses[dir] = sf::IntRect(
            3 * _pos.x * _spriteSize.x + _spriteSize.x * _clock,
            4 * _pos.y * _spriteSize.y + _spriteSize.y * y++,
            _spriteSize.x,
            _spriteSize.y
        );
}

sf::IntRect Team::getPose(std::string pose)
{
    return _poses[pose];
}

void Team::setId(int id)
{
    _id = id;
    _pos = {_id % 4, _id / 4 % 2};
    updatePose();
}

int Team::getId()
{
    return _id;
}

std::string Team::getName()
{
    return _name;
}

void Team::setName(std::string name)
{
    _name = name;
}
