/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Cone.hpp
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "Object.hpp"

class Cone : public AObject {
    public:
        Cone();
        Cone(double size, Vector3d position, std::vector<double> color);

        ~Cone();
};

#endif /* CONE_HPP_ */
