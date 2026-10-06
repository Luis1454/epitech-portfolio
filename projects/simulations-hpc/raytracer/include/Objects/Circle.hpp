/*
** EPITECH PROJECT, 2024
** Circle.hpp
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
    #define CIRCLE_HPP_

    #include "Plane.hpp"

class Circle : public Plane {
    public:
        Circle();
        Circle(double size, Vector3d position, Color color, Vector3d normal);
        ~Circle();

        Vector3d getSize();
        void setSize(Vector3d size);

        bool intersect(Ray &ray) override;
        std::shared_ptr<AObject> clone() override;
        void reflect(Ray &ray) override;
        Vector3d getNormal(Vector3d point) override;
    private:
        Vector3d _size;
};

#endif /* !CIRCLE_HPP_ */
