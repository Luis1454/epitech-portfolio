/*
** EPITECH PROJECT, 2024
** LightPoint.hpp
** File description:
** LightPoint
*/

#ifndef LIGHTPOINT_HPP_
    #define LIGHTPOINT_HPP_

    #include "../Physics/Light.hpp"
    #include "../Physics/Ray.hpp"

class LightPoint : public Light {
    public:
        LightPoint();
        ~LightPoint();

    void illuminate(Ray &ray, Vector3d normal) override;
};

#endif /* !LIGHTPOINT_HPP_ */
