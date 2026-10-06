/*
** EPITECH PROJECT, 2024
** Ambient.cpp
** File description:
** Ambient
*/

#include "../../include/Lights/Ambient.hpp"

Ambient::Ambient()
{
    _type = "Ambient";
    setIntensity(0.5);
}

Ambient::~Ambient()
{
}

bool Ambient::isVisible(ObjectList objects, Ray &ray)
{
    (void)objects;
    (void)ray;
    return true;
}

void Ambient::illuminate(Ray &ray, Vector3d normal)
{
    (void)normal;
    ray.setColor(getColor() * getIntensity());
}
