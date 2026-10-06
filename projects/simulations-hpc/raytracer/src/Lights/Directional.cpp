/*
** EPITECH PROJECT, 2024
** Directional.cpp
** File description:
** Directional
*/

#include "../../include/Lights/Directional.hpp"

Directional::Directional()
{
    _type = "Directional";
    setDirection(Vector3d(0, 0, -1));
}

Directional::Directional(Vector3d direction)
{
    _type = "Directional";
    setDirection(direction);
}

Directional::~Directional()
{
}

bool Directional::isVisible(ObjectList objects, Ray &ray)
{
    Ray r = ray;

    r.setDirection(-getDirection());
    for (auto &object : objects)
        if (object->intersect(r))
            return false;
    return true;
}

void Directional::illuminate(Ray &ray, Vector3d normal)
{
    ray.setColor((getColor() * normal.dot(-getDirection()) * getIntensity()));
}
