/*
** EPITECH PROJECT, 2024
** Ambient.hpp
** File description:
** Ambient.hpp
*/

#ifndef AMBIENT_HPP_
    #define AMBIENT_HPP_

    #include "../Physics/Light.hpp"
    #include "../Physics/Ray.hpp"

class Ambient : public Light {
    public:
        Ambient();
        ~Ambient();

    void illuminate(Ray &ray, Vector3d normal) override;
    bool isVisible(ObjectList objects, Ray &ray) override;
};

#endif /* !AMBIENT_HPP_ */
