/*
** EPITECH PROJECT, 2024
** Ray.cpp
** File description:
** Ray
*/

#include "../../include/Physics/Ray.hpp"

Ray::Ray()
{
    _bounces = 0;
    _origin = Vector3d();
}

Ray::Ray(Vector3d origin, Vector3d direction)
{
    _bounces = 0;
    _origin = origin;
    setDirection(direction);
}

Ray::~Ray()
{
}

void Ray::setOrigin(Vector3d origin)
{
    _origin = origin;
}

void Ray::incrementBounces()
{
    _bounces++;
}

void Ray::normalize()
{
    setDirection(getDirection().normalized());
}

Vector3d Ray::getOrigin()
{
    return _origin;
}

int Ray::getBounces()
{
    return _bounces;
}
