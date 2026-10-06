/*
** EPITECH PROJECT, 2024
** Cylinder.cpp
** File description:
** Cylinder
*/

#include "../../include/Objects/Cylinder.hpp"
#include "../../include/Objects/Circle.hpp"
#include "../../include/Physics/Matrix.hpp"

Cylinder::Cylinder()
{
    _radius = 0.25;
    _position = Vector3d(0, 0, 0);
    _color = Color(1, 1, 1);
    _height = 1;
    _normal = Vector3d(0, 0, 0);
}

Cylinder::Cylinder(double radius,  double height,
    Vector3d position, Vector3d normal, Color color)
{
    _radius = radius;
    _position = position;
    _color = color;
    _height = height;
    _normal = normal;
}

Cylinder::~Cylinder() {}

std::shared_ptr<AObject> Cylinder::clone()
{
    Cylinder obj(_radius, _height, _position, _normal, _color);
    obj._lastIntersect = _lastIntersect;
    return std::make_shared<Cylinder>(obj);
}
bool Cylinder::intersect(Ray &ray)
{
    Circle top(_radius, _position + Vector3d(0, 0, _height), _color, {0, 0, 1});
    Circle bottom(_radius, _position - Vector3d(0, 0, 0), _color, {0, 0, -1});
    std::vector<Vector3d> intersects;

    Vector3d oc = ray.getOrigin() - _position;
    double a = ray.getDirection().getX() * ray.getDirection().getX() + ray.getDirection().getY() * ray.getDirection().getY();
    double b = 2 * (oc.getX() * ray.getDirection().getX() + oc.getY() * ray.getDirection().getY());
    double c = oc.getX() * oc.getX() + oc.getY() * oc.getY() - _radius * _radius;
    double delta = b * b - 4 * a * c;
    double t = 0;
    double t1 = 0;
    double t2 = 0;

    if (top.intersect(ray))
        intersects.push_back(top.getLastIntersect());
    if (bottom.intersect(ray))
        intersects.push_back(bottom.getLastIntersect());

    if (delta < 0)
        return false;
    t1 = (-b - sqrt(delta)) / (2 * a);
    t2 = (-b + sqrt(delta)) / (2 * a);
    if (t1 < 0 && t2 < 0)
        return false;
    t = (t1 < t2) ? t1 : t2;
    if (t < 0)
        t = (t1 > t2) ? t1 : t2;
    if (t < 0)
        return false;
    
    Vector3d curve = ray.getOrigin() + ray.getDirection() * t;
    _lastIntersect = curve;
    if (curve.getZ() < _position.getZ() || curve.getZ() > _position.getZ() + _height) {
        if (intersects.empty())
            return false;
        _lastIntersect = (intersects[0].distance(ray.getOrigin()) < intersects[1].distance(ray.getOrigin())) ? intersects[0] : intersects[1];
    }
    if (curve.distance(ray.getOrigin()) > ray.getOrigin().distance(curve))
        _lastIntersect = curve;
    return true;
}

void Cylinder::reflect(Ray &ray)
{
    Vector3d normal = getNormal(_lastIntersect);
    Vector3d reflect = ray.getDirection() - normal * 2 * ray.getDirection().dot(normal);
    ray.setDirection(reflect);
}

Vector3d Cylinder::getNormal(Vector3d point)
{
    Vector3d normal = point - _position;
    normal.setZ(0);
    normal.normalize();
    return normal;
}
