/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Position
*/

#include "Position.hpp"

void Position::info() const
{
    std::cout << "Position (" << _pos.size() << ")" << std::endl;
    for (auto it : _pos)
        std::cout << it.first << " -> " << it.second.x << " , " << it.second.y << std::endl;
}

void Position::dropEntity(int idx) {
    Component::dropEntity(idx);

    _pos.erase(idx);
}

void Position::setX(std::size_t idx, float x)
{
    _pos[idx].x = x;
}

void Position::setY(std::size_t idx, float y)
{
    _pos[idx].y = y;
}

void Position::set(std::size_t idx, pos_t pos)
{
    _pos[idx] = pos;
}

void Position::add(std::size_t idx, pos_t speed)
{
    if (_pos.find(idx) == _pos.end())
        _pos[idx] = speed;
    else {
        _pos[idx].x = _pos.at(idx).x + speed.x;
        _pos[idx].y = _pos.at(idx).y + speed.y;
    }
}

float Position::getX(std::size_t idx)
{
    if (_pos.find(idx) == _pos.end())
        return 0;
    return _pos.at(idx).x;
}

float Position::getY(std::size_t idx)
{
    if (_pos.find(idx) == _pos.end())
        return 0;
    return _pos.at(idx).y;
}
