/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "Object.hpp"
    #include "../Physics/Ray.hpp"

class Plane : public AObject {
    public:
        Plane();
        Plane(Vector3d position, Vector3d normal, Color color);

        std::shared_ptr<AObject> clone() override;
        ~Plane();

        void flipNormal();
        void setNormal(Vector3d normal);

        Vector3d getNormal();
        Vector3d getNormal(Vector3d point);

        bool intersect(Ray &ray) override;
        void reflect(Ray &ray) override;

    protected:
        Vector3d _normal;
};

#endif /* PLANE_HPP_ */