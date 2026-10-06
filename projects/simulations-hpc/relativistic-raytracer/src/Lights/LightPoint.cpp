/*
** EPITECH PROJECT, 2024
** LightPoint.cpp
** File description:
** LightPoint
*/

#include "../../include/Lights/LightPoint.hpp"

LightPoint::LightPoint()
{
    _type = "LightPoint";
    setPosition(Vector3d(0, 0, 0));
    setIntensity(1);
}

LightPoint::~LightPoint()
{
}

void LightPoint::illuminate(Ray &ray, Vector3d normal)
{
    Vector3d dir = getPosition() - ray.getOrigin();
    dir.normalize();
    ray.setColor((getColor() * normal.dot(dir) * getIntensity() *
        std::pow((getPosition() - ray.getOrigin()).getMagnitude(), 2)));
}
