/*
** EPITECH PROJECT, 2024
** Spot.hpp
** File description:
** Spot
*/

#ifndef SPOT_HPP_
    #define SPOT_HPP_

    #include "../Physics/Light.hpp"

class Spot : public Light, public Vector3d {
    public:
        Spot();
        Spot(Vector3d position, double intensity, Color color, Vector3d direction);
        ~Spot();

        void setConeSize(double angle);

        double getConeSize();

    private:
        double _angle;
};

#endif /* !SPOT_HPP_ */
