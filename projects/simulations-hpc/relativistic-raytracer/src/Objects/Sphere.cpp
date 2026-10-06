/*
** EPITECH PROJECT, 2024
** Sphere.cpp
** File description:
** Sphere
*/

#include "../../include/Objects/Sphere.hpp"

Sphere::Sphere(double size, Vector3d position, Color color)
{
    setSize(size);
    setPosition(position);
    setColor(color);
}

Sphere::Sphere()
{
    setSize(1);
    setPosition(Vector3d(0, 0, 0));
    setColor(Color(1.0, 1.0, 1.0));
}

Sphere::~Sphere()
{
}

std::shared_ptr<AObject> Sphere::clone()
{
    Sphere obj(getSize(), getPosition(), getColor());

    obj._lastIntersect = _lastIntersect;

    return std::make_shared<Sphere>(obj);
}

bool Sphere::intersect(Ray &ray)
{
    Vector3d oc = ray.getOrigin() - getPosition();
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - (getSize() * getSize());
    double delta = b * b - 4 * a * c;

    if (delta < 0)
        return false;
    double t1 = (-b - std::sqrt(delta)) / (2 * a);
    double t2 = (-b + std::sqrt(delta)) / (2 * a);
    double t = (t1 < t2) ? t1 : t2;
    if (t < 0)
        return false;
    _lastIntersect = ray.getOrigin() + ray.getDirection() * t;
    return true;
}

void Sphere::reflect(Ray &ray)
{
    Vector3d normal = getNormal(_lastIntersect);
    Vector3d reflect = ray.getDirection() - normal * 2 * ray.getDirection().dot(normal);
    ray.setDirection(reflect);
}

Vector3d Sphere::getNormal(Vector3d point)
{
    return (point - getPosition()).normalized();
}
