/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Velocity
*/

#include "Velocity.hpp"

void Velocity::info() const
{
    std::cout << "Velocity (" << _vel.size() << ")" << std::endl;
    for (auto &value : _vel)
        std::cout << value.first << " -> speed : " << value.second.speed << ", dir : " << value.second.dir << std::endl;
}

void Velocity::dropEntity(int idx)
{
    Component::dropEntity(idx);

    _vel.erase(idx);
}

void Velocity::setSpeed(std::size_t idx, float speed)
{
    _vel[idx].speed = speed;
}

void Velocity::setDir(std::size_t idx, float dir)
{
    _vel[idx].dir = dir;
}

void Velocity::set(std::size_t idx, float speed, float dir)
{
    _vel[idx].speed = speed;
    _vel[idx].dir = dir;
}

float Velocity::getSpeed(std::size_t idx)
{
    if (_vel.find(idx) == _vel.end())
        return 0;
    return _vel[idx].speed;
}

float Velocity::getDir(std::size_t idx)
{
    if (_vel.find(idx) == _vel.end())
        return 0;
    return _vel[idx].dir;
}

std::pair<float, float> Velocity::get(std::size_t idx)
{
    return {_vel[idx].speed, _vel[idx].dir};
}
