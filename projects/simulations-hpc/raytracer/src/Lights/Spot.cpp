/*
** EPITECH PROJECT, 2024
** Spot.cpp
** File description:
** Spot
*/

#include "../../include/Lights/Spot.hpp"

Spot::Spot()
{
    setPosition(Vector3d(0, 0, 1));
    setDirection(Vector3d(0, 0, -1));
    _angle = 35;
}

Spot::Spot(Vector3d position, double intensity, Color color, Vector3d direction)
{
    setPosition(position);
    setIntensity(intensity);
    setDirection(direction);
    setColor(color);
    _angle = 35;
}

Spot::~Spot() {}

void Spot::setConeSize(double angle)
{
    _angle = angle;
}

double Spot::getConeSize()
{
    return _angle;
}
