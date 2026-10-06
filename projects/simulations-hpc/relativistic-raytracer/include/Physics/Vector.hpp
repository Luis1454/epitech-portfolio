/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Vector.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

    #include "Matrix.hpp"
    #include <iostream>
    #include <climits>
    #include <cmath>

class Vector {
    public:
        virtual double norm() const = 0;
};

class Vector3d : public Vector {
    public:
        Vector3d();
        Vector3d(double size);
        Vector3d(double x, double y, double z);
        Vector3d(double x, double y, double z, double w);

        ~Vector3d();

        double norm() const;
        double distance(const Vector3d v);
        double dot(const Vector3d v);
        virtual void rotate(Vector3d v, double angle);
        virtual void rotate(Vector3d v);
        Vector3d cross(const Vector3d v);
        Vector3d normalized();
        void normalize();
        Vector3d absolute();
        double getMagnitude();

        double getX() const;
        double getY() const;
        double getZ() const;
        double getW() const;

        void setX(double x) { _x = x; }
        void setY(double y) { _y = y; }
        void setZ(double z) { _z = z; }
        void setW(double w) { _w = w; }

        double getAngle(const Vector3d v);

        virtual void setDirection(Vector3d direction);
        virtual void setDirection(double x, double y, double z);

        virtual void lookAt(Vector3d origin, Vector3d target);

        Vector3d getDirection() const;

        void randomize();
        void randomize(Vector3d dir, double angle);
        Vector3d randomized();

        double &operator[](int index);

        const double &operator[](int index) const;

        auto begin();

        auto begin() const;

        Vector3d operator+(const Vector3d &v);
        Vector3d operator-();
        Vector3d operator-(const Vector3d &v);
        Vector3d operator*(const Vector3d &v);
        Vector3d operator*(const double &v);
        Vector3d operator/(const Vector3d &v);
        Vector3d operator/(const double &v);
        Vector3d operator+=(const Vector3d &v);
        Vector3d operator-=(const Vector3d &v);
        Vector3d operator*=(const Vector3d &v);
        Vector3d operator*=(const double &v);
        Vector3d operator/=(const Vector3d &v);
        Vector3d operator/=(const double &v);

        Vector3d operator=(Matrix<double> m);
        Vector3d operator+(Matrix<double> m);
        Vector3d operator-(Matrix<double> m);
        Vector3d operator*(Matrix<double> m);
        Vector3d operator%(Matrix<double> m);
        Vector3d operator^(Matrix<double> m);
        Vector3d operator|(Matrix<double> m);
        Vector3d operator+=(Matrix<double> m);
        Vector3d operator-=(Matrix<double> m);
        Vector3d operator*=(Matrix<double> m);
        Vector3d operator%=(Matrix<double> m);
        Vector3d operator^=(Matrix<double> m);
        Vector3d operator|=(Matrix<double> m);

        bool operator==(Matrix<double> m);
        bool operator!=(Matrix<double> m);
        bool operator<(Matrix<double> m);
        bool operator>(Matrix<double> m);
        bool operator<=(Matrix<double> m);
        bool operator>=(Matrix<double> m);

        bool operator==(const Vector3d &v);
        bool operator!=(const Vector3d &v);
        bool operator>(const Vector3d &v);
        bool operator<(const Vector3d &v);
        bool operator>=(const Vector3d &v);
        bool operator<=(const Vector3d &v);

        friend std::ostream &operator<<(std::ostream &os, const Vector3d &v);
        friend std::istream &operator>>(std::istream &is, Vector3d &v);

    private:
        double _x;
        double _y;
        double _z;
        double _w;
};

#endif /* VECTOR_HPP_ */
