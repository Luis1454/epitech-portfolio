/*
** EPITECH PROJECT, 2024
** Plane.cpp
** File description:
** Plane
*/

#include "../../include/Objects/Plane.hpp"

Plane::Plane()
{
    _position = Vector3d();
    _normal = (Vector3d(0, 0, 1));
    _color = Color(1.0, 1.0, 1.0);
}

Plane::Plane(Vector3d position, Vector3d normal, Color color)
{
    _position = position;
    _normal = normal;
    _color = color;
}

std::shared_ptr<AObject> Plane::clone()
{
    Plane obj(_position, _normal, _color);

    obj._lastIntersect = _lastIntersect;

    return std::make_shared<Plane>(obj);
}

Plane::~Plane()
{
}

bool Plane::intersect(Ray &ray)
{
    ray.normalize();
    double t = (_position - ray.getOrigin()).dot(_normal) / ray.getDirection().dot(_normal);

    if (t < 0)
        return false;
    _lastIntersect = ray.getOrigin() + ray.getDirection() * t;
    return true;
}

void Plane::reflect(Ray &ray)
{
    Vector3d normal = getNormal();

    Vector3d dir = ray.getDirection() - normal * 2 * ray.getDirection().dot(normal);
    ray.setDirection(dir);
}

Vector3d Plane::getNormal()
{
    return _normal;
}

Vector3d Plane::getNormal(Vector3d point)
{
    (void)point;
    return _normal;
}

void Plane::setNormal(Vector3d normal)
{
    _normal = normal;
}

void Plane::flipNormal()
{
    _normal *= -1.0;
}
