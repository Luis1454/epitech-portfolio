/*
** EPITECH PROJECT, 2024
** Directional.hpp
** File description:
** Directional
*/

#ifndef DIRECTIONAL_HPP_
    #define DIRECTIONAL_HPP_

    #include "../Physics/Vector.hpp"
    #include "../Physics/Light.hpp"
    #include "../Physics/Ray.hpp"

class Directional : public Light, public Vector3d {
    public:
        Directional();
        Directional(Vector3d direction);
        ~Directional();

        void illuminate(Ray &ray, Vector3d normal) override;
        bool isVisible(ObjectList objects, Ray &ray) override;
};

#endif /* !DIRECTIONAL_HPP_ */
