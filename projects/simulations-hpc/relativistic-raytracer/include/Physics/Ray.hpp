/*
** EPITECH PROJECT, 2024
** Ray.hpp
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

    #include "../Objects/Object.hpp"
    #include "../Physics/Vector.hpp"
    #include "../Physics/Light.hpp"
    #include <vector>
    #include <memory>

class Ray : public Vector3d, public APoint, public Color {
    public:
        Ray();
        Ray(Vector3d origin, Vector3d direction);
        ~Ray();
        void setOrigin(Vector3d origin);
        void incrementBounces();
        void normalize();
        Vector3d getOrigin();
        int getBounces();

    private:
        Vector3d _origin;
        std::vector<AObject> _intersected;
        int _bounces;
};

#endif /* !RAY_HPP_ */
