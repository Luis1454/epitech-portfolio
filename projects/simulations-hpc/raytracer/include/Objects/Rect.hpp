/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Rect.hpp
*/

#ifndef Rect_HPP_
    #define Rect_HPP_

    #include "Plane.hpp"

class Rect : public Plane {
    public:
        Rect();
        Rect(Vector3d size, Vector3d position, Color color);
        ~Rect();
        Vector3d getSize();
        void setSize(Vector3d size);

        bool intersect(Ray &ray) override;
        std::shared_ptr<AObject> clone() override;
    private:
        Vector3d _size;
};

#endif /* Rect_HPP_ */