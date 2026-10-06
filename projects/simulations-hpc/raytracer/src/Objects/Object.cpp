/*
** EPITECH PROJECT, 2024
** Object.cpp
** File description:
** Object
*/

#include "../../include/Objects/Object.hpp"
#include "../../include/Physics/Ray.hpp"

AObject::AObject()
{
}

AObject::AObject(double size, Vector3d position, Color color)
{
    _size = size;
    _position = position;
    _color = color;
}

AObject::~AObject()
{
}

std::shared_ptr<AObject> AObject::clone()
{
    AObject obj;

    obj._lastIntersect = _lastIntersect;
    obj._position = _position;
    obj._size = _size;
    obj._color = _color;

    return std::make_shared<AObject>(obj);
}

void AObject::setSize(double size)
{
    _size = size;
}

void AObject::setColor(Color color)
{
    _color = color;
}

double AObject::getSize()
{
    return _size;
}

Color AObject::getColor()
{
    return _color;
}

bool AObject::intersect(Ray &ray)
{
    (void)ray;
    return false;
}

void AObject::reflect(Ray &ray)
{
    ray.normalize();
    ray.setDirection(-ray.getDirection());
}

Vector3d AObject::getLastIntersect()
{
    return _lastIntersect;
}
