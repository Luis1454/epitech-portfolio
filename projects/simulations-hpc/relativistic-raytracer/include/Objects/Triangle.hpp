/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Triangle.hpp
*/

#ifndef TRIANGLE_HPP_
    #define TRIANGLE_HPP_

    #include "Object.hpp"
    #include "Plane.hpp"

class Triangle : public Plane {
    public:
        Triangle();
        Triangle(double &size, Vector3d &position, std::vector<double> &color);

        ~Triangle();
};

#endif /* TRIANGLE_HPP_ */
