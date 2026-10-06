/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Cube.hpp
*/

#ifndef CUBE_HPP_
    #define CUBE_HPP_

    #include "Object.hpp"

class Cube : public AObject {
    public:
        Cube();
        Cube(double size, Vector3d position, Color color);

        ~Cube();

        bool intersect(Ray &ray) override;
};

#endif /* CUBE_HPP_ */
