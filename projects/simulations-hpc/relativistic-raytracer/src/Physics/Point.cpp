/*
** EPITECH PROJECT, 2024
** APoint.cpp
** File description:
** APoint
*/

#include "../../include/Physics/Point.hpp"

APoint::APoint()
{
    _position = Vector3d();
}

APoint::~APoint()
{
}

void APoint::setPosition(Vector3d position)
{
    _position = position;
}

Vector3d APoint::getPosition()
{
    return _position;
}

Vector3d APoint::getNormal(Vector3d point)
{
    (void)point;
    return Vector3d(0, 0, 0);
}
