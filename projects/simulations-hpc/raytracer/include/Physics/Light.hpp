/*
** EPITECH PROJECT, 2024
** Light.hpp
** File description:
** Light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "../Objects/Object.hpp"
#include <memory>

class Light : public APoint, public Color {
    public:
        Light();
        Light(Vector3d position, double intensity, Color color);
        ~Light();

        std::string getType();

        void setIntensity(double intensity);
        double getIntensity();
        double getRadius();
        void setRadius(double radius);

        virtual bool isVisible(ObjectList objects, Ray &ray);
        virtual void illuminate(Ray &ray, Vector3d normal);

    private:
        double _intensity;
        double _radius;

    protected:
        std::string _type;
};

#endif /* !LIGHT_HPP_ */
