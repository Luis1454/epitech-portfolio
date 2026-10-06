/*
** EPITECH PROJECT, 2024
** Camera.cpp
** File description:
** Camera
*/

#include "../../include/Engine/Camera.hpp"
#include "../../include/Physics/Ray.hpp"
#include "../../include/Objects/Rect.hpp"
#include "../../include/Objects/Circle.hpp"

Camera::Camera()
{
    _speed = {0, 0, 0};
    _fov = 65.0;
    _width = 800;
    _height = 600;
}

Camera::~Camera()
{
}

void Camera::render()
{
}

void Camera::setSpeed(Vector3d speed)
{
    _speed = speed;
}

void Camera::setFov(double fov)
{
    _fov = fov * M_PI / 180;
}

void Camera::setWidth(double width)
{
    _width = width;
}

void Camera::setHeight(double height)
{
    _height = height;
}

void Camera::setSize(double width, double height)
{
    _width = width;
    _height = height;
}

double Camera::getWidth()
{
    return _width;
}

double Camera::getHeight()
{
    return _height;
}

std::vector<double> Camera::getSize()
{
    return std::vector<double>{_width, _height};
}

Vector3d Camera::getSpeed()
{
    return _speed;
}

double Camera::getFov()
{
    return _fov;
}

Vector3d Camera::getOrientation(Vector3d dir)
{
    Vector3d up(0, 1, 0);
    Vector3d right = getDirection().cross(up);
    up = right.cross(getDirection());
    right.normalize();
    up.normalize();
    return getDirection() + right * dir.getX() + up * dir.getY();
}

void Camera::rotate(Vector3d axis, double angle)
{
    Vector3d v = getDirection();
    v.rotate(axis, angle);
    setDirection(v);
}

void Camera::rotate(Vector3d axis)
{
    Vector3d v = getDirection();
    v.rotate(axis);
    setDirection(v);
}
