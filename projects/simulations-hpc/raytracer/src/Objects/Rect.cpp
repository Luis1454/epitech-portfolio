/*
** EPITECH PROJECT, 2024
** Rect.cpp
** File description:
** Rect
*/

#include "../../include/Objects/Rect.hpp"

Rect::Rect()
{
    _size = Vector3d(1, 1, 0);
    _position = Vector3d(0, 0, 0);
    _color = Color(1, 1, 1);
    _normal = Vector3d(0, 0, 1);
}

Rect::Rect(Vector3d size, Vector3d pos, Color color)
{
    _size = size;
    _position = pos;
    _color = color;
    _normal = Vector3d(0, 0, 1);
}

Rect::~Rect() {}

bool Rect::intersect(Ray &ray)
{
    Plane plane(_position, _normal, _color);

    if (!plane.intersect(ray))
        return false;
    Vector3d pos = plane.getLastIntersect() - _position;
    if (pos.getX() >= -getSize().getX() / 2 && pos.getX() <= getSize().getX() / 2
    && pos.getY() >= -getSize().getY() / 2 && pos.getY() <= getSize().getY() / 2) {
        _lastIntersect = plane.getLastIntersect();
        return true;
    }
    return false;
}

std::shared_ptr<AObject> Rect::clone()
{
    Rect obj(_size, _position, _color);
    obj._normal = _normal;
    obj._lastIntersect = _lastIntersect;
    return std::make_shared<Rect>(obj);
}

Vector3d Rect::getSize()
{
    return _size;
}

void Rect::setSize(Vector3d size)
{
    _size = size;
}
