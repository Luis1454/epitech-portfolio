/*
** EPITECH PROJECT, 2024
** Point.hpp
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Vector.hpp"

class Point {
    virtual void setPosition(Vector3d position) = 0;
    virtual Vector3d getPosition() = 0;
    virtual Vector3d getNormal(Vector3d point) = 0;
};

class APoint : public Point {
    public:
        APoint();
        ~APoint();

        virtual void setPosition(Vector3d position);
        virtual Vector3d getPosition();
        virtual Vector3d getNormal(Vector3d point);
    private:
        Vector3d _position;
};

#endif /* !POINT_HPP_ */
