/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Object.hpp
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include "../Physics/Point.hpp"
    #include "../Physics/Color.hpp"
    #include <iostream>
    #include <memory>

    class Ray;

class AObject : public APoint {
    public:
        AObject();
        AObject(double size, Vector3d position, Color color);

        ~AObject();

        virtual std::shared_ptr<AObject> clone();
        virtual void setSize(double size);
        virtual void setColor(Color color);

        double getSize();
        virtual Color getColor();
        virtual bool intersect(Ray &ray);
        virtual void reflect(Ray &ray);
        virtual Vector3d getLastIntersect();

    protected:
        double _size;
        Vector3d _position;
        Vector3d _lastIntersect;
        Color _color;
};

typedef std::vector<std::shared_ptr<AObject>> ObjectList;

#endif /* OBJECT_HPP_ */
