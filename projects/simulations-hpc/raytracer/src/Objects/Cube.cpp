/*
** EPITECH PROJECT, 2024
** Cube.cpp
** File description:
** Cube
*/

#include "../../include/Objects/Cube.hpp"
#include "../../include/Objects/Plane.hpp"

Cube::Cube()
{
    _position = Vector3d();
    _size = 1;
}

Cube::Cube(double size, Vector3d position, Color color)
{
    _size = size;
    _position = position;
    _color = color;
}

Cube::~Cube()
{
}

bool Cube::intersect(Ray &ray)
{
    Vector3d p = _position;
    Vector3d size = Vector3d(_size, _size, 0);

    Plane left(Vector3d(p.getX() - _size / 2, p.getY(), p.getZ()), Vector3d(-1, 0, 0), _color);
    Plane right(Vector3d(p.getX() + _size / 2, p.getY(), p.getZ()), Vector3d(1, 0, 0), _color);
    Plane top(Vector3d(p.getX(), p.getY() + _size / 2, p.getZ()), Vector3d(0, 1, 0), _color);
    Plane bottom(Vector3d(p.getX(), p.getY() - _size / 2, p.getZ()), Vector3d(0, -1, 0), _color);
    Plane front(Vector3d(p.getX(), p.getY(), p.getZ() + _size / 2), Vector3d(0, 0, 1), _color);
    Plane back(Vector3d(p.getX(), p.getY(), p.getZ() - _size / 2), Vector3d(0, 0, -1), _color);

    if (left.intersect(ray))
        _lastIntersect = left.getLastIntersect();
    else if (right.intersect(ray))
        _lastIntersect = right.getLastIntersect();
    else if (top.intersect(ray))
        _lastIntersect = top.getLastIntersect();
    else if (bottom.intersect(ray))
        _lastIntersect = bottom.getLastIntersect();
    else if (front.intersect(ray))
        _lastIntersect = front.getLastIntersect();
    else if (back.intersect(ray))
        _lastIntersect = back.getLastIntersect();
    ray.setOrigin(_lastIntersect);
    ray.setDirection(ray.getDirection() * -1);
    if (left.intersect(ray) || right.intersect(ray) || top.intersect(ray)
    || bottom.intersect(ray) || front.intersect(ray) || back.intersect(ray))
        return true;
    return false;
}
