/*
** EPITECH PROJECT, 2024
** Light.cpp
** File description:
** Light
*/

#include "../../include/Physics/Light.hpp"
#include "../../include/Physics/Ray.hpp"
#include "../../include/RayTracer.hpp"

Light::Light()
{
    _intensity = 1.0;
    setColor(Color(1.0, 1.0, 1.0));
}

Light::Light(Vector3d position, double intensity, Color color)
{
    setPosition(position);
    _intensity = intensity;
    setColor(color);
}

Light::~Light()
{
}

std::string Light::getType()
{
    return _type;
}

void Light::setIntensity(double intensity)
{
    _intensity = intensity;
}

double Light::getIntensity()
{
    return _intensity;
}

double Light::getRadius()
{
    return _radius;
}

void Light::setRadius(double radius)
{
    _radius = radius;
}

bool Light::isVisible(ObjectList objects, Ray &ray)
{
    Ray r = ray;

    r.setDirection(getPosition() - ray.getOrigin());
    for (auto &object : objects)
        if (object->intersect(r))
            return false;
    return true;
}

void Light::illuminate(Ray &ray, Vector3d normal)
{
    (void)normal;
    ray.setColor(getColor());
}
