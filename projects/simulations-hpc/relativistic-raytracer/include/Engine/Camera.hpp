/*
** EPITECH PROJECT, 2024
** Camera.hpp
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "../Objects/Object.hpp"

class Camera : public Vector3d, public APoint {
    public:
        Camera();
        ~Camera();

        void render();

        void setSpeed(Vector3d speed);
        void setFov(double fov);
        void setWidth(double width);
        void setHeight(double height);
        void setSize(double width, double height);

        Vector3d getSpeed();
        double getFov();
        double getWidth();
        double getHeight();
        std::vector<double> getSize();

        void rotate(Vector3d axis, double angle) override;
        void rotate(Vector3d axis) override;

        Vector3d getOrientation(Vector3d dir);

    private:
        Vector3d _speed;
        double _width;
        double _height;
        double _fov;
};

#endif /* !CAMERA_HPP_ */
