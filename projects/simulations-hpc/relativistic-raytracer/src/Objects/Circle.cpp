/*
** EPITECH PROJECT, 2024
** Circle.cpp
** File description:
** Circle
*/

#include "../../include/Objects/Circle.hpp"

Circle::Circle() {
    _size = {1, 0, 0};
}

Circle::Circle(double size, Vector3d position, Color color, Vector3d normal) {
    _size = {size, 0, 0};
    _position = position;
    _color = color;
    _normal = normal;
}

Circle::~Circle() {}

void Circle::setSize(Vector3d size) {
    _size = size;
}

Vector3d Circle::getSize() {
    return _size;
}

bool Circle::intersect(Ray &ray) {
    Plane plane(_position, _normal, _color);

    if (!plane.intersect(ray))
        return false;
    if (_position.distance(plane.getLastIntersect()) < _size.getX()) {
        _lastIntersect = plane.getLastIntersect();
        return true;
    }
    return false;
}

void Circle::reflect(Ray &ray) {
    Plane plane(_position, _normal, _color);

    plane.reflect(ray);
}

Vector3d Circle::getNormal(Vector3d point) {
    (void)point;
    return _normal;
}

std::shared_ptr<AObject> Circle::clone() {
    Circle obj(_size.getX(), _position, _color, _normal);
    obj._lastIntersect = _lastIntersect;
    return std::make_shared<Circle>(obj);
}