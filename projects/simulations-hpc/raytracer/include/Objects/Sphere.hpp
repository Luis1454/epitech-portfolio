/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Sphere.hpp
*/

#ifndef Sphere_HPP_
    #define Sphere_HPP_

    #include "Object.hpp"
    #include "../Physics/Ray.hpp"

class Sphere : public AObject {
    public:
        Sphere();
        Sphere(double size, Vector3d position, Color color);
        ~Sphere();

        std::shared_ptr<AObject> clone() override;
        bool intersect(Ray &ray) override;
        void reflect(Ray &ray) override;
        Vector3d getNormal(Vector3d point) override;

};

#endif /* Sphere_HPP_ */