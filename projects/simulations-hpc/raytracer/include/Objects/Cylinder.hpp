/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Cylinder.hpp
*/

#ifndef CYLINDERHPP
    #define CYLINDERHPP

    #include "Object.hpp"
    #include "../Physics/Ray.hpp"

class Cylinder : public AObject {
    public:
        Cylinder();
        Cylinder(double radius, double height, Vector3d position, Vector3d normal, Color color);
        ~Cylinder();

        std::shared_ptr<AObject> clone() override;
        bool intersect(Ray &ray) override;
        void reflect(Ray &ray) override;
        Vector3d getNormal(Vector3d point) override;

    private:
        double _radius;
        double _height;
        Vector3d _normal;

};

#endif /* CYLINDERHPP */