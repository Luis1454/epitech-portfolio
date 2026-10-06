/*
** EPITECH PROJECT, 2024
** Vector.cpp
** File description:
** Vector
*/

#include "../../include/Physics/Vector.hpp"

Vector3d::Vector3d()
{
    _x = 0;
    _y = 0;
    _z = 0;
    _w = 0;
}

Vector3d::Vector3d(double size)
{
    _x = size;
    _y = size;
    _z = size;
    _w = 0;
}

Vector3d::Vector3d(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
    _w = 0;
}

Vector3d::Vector3d(double x, double y, double z, double w)
{
    _x = x;
    _y = y;
    _z = z;
    _w = w;
}

Vector3d::~Vector3d() {}

double Vector3d::norm() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

double Vector3d::distance(const Vector3d v)
{
    return std::sqrt(std::pow(v._x - _x, 2) + std::pow(v._y - _y, 2) + std::pow(v._z - _z, 2));
}

double Vector3d::dot(const Vector3d v)
{
    return _x * v._x + _y * v._y + _z * v._z;
}

void Vector3d::rotate(Vector3d v, double angle)
{
    Vector3d ref = Vector3d(_x, _y, _z, _w);

    _x = ref._x * (std::cos(angle) + (1 - std::cos(angle)) * v._x * v._x) +
        ref._y * ((1 - std::cos(angle)) * v._x * v._y - std::sin(angle) * v._z) +
        ref._z * ((1 - std::cos(angle)) * v._x * v._z + std::sin(angle) * v._y);
    _y = ref._x * ((1 - std::cos(angle)) * v._y * v._x + std::sin(angle) * v._z) +
        ref._y * (std::cos(angle) + (1 - std::cos(angle)) * v._y * v._y) +
        ref._z * ((1 - std::cos(angle)) * v._y * v._z - std::sin(angle) * v._x);
    _z = ref._x * ((1 - std::cos(angle)) * v._z * v._x - std::sin(angle) * v._y) +
        ref._y * ((1 - std::cos(angle)) * v._z * v._y + std::sin(angle) * v._x) +
        ref._z * (std::cos(angle) + (1 - std::cos(angle)) * v._z * v._z);
}

void Vector3d::rotate(Vector3d v)
{
    // get the angle between 1 0 0 and the vector

    double angle = std::acos(v._x / v.norm());

    // rotate the vector by the angle
    Matrix<double> m(4, 4);

    rotate(v, angle);
}

double Vector3d::getX() const
{
    return _x;
}

double Vector3d::getY() const
{
    return _y;
}

double Vector3d::getZ() const
{
    return _z;
}

double Vector3d::getW() const
{
    return _w;
}

Vector3d Vector3d::cross(const Vector3d v)
{
    return Vector3d(
        _y * v._z - _z * v._y,
        _z * v._x - _x * v._z,
        _x * v._y - _y * v._x
    );
}

void Vector3d::normalize()
{
    double n = norm();
    _x /= n;
    _y /= n;
    _z /= n;
}

Vector3d Vector3d::normalized()
{
    double n = norm();
    return Vector3d(_x / n, _y / n, _z / n);
}

Vector3d Vector3d::absolute()
{
    return Vector3d(
        _x < 0 ? -_x : _x,
        _y < 0 ? -_y : _y,
        _z < 0 ? -_z : _z
    );
}

double Vector3d::getMagnitude()
{
    return 1.0 / (norm() * norm());
}

void Vector3d::setDirection(Vector3d direction)
{
    _x = direction._x;
    _y = direction._y;
    _z = direction._z;
    if (direction._x == 0 && direction._y == 0 && direction._z == 0)
        _x = 1;
}

void Vector3d::setDirection(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
    if (x == 0 && y == 0 && z == 0)
        _x = 1;
}

Vector3d Vector3d::getDirection() const
{
    return Vector3d(_x, _y, _z);
}

double Vector3d::getAngle(const Vector3d v)
{
    return std::acos(dot(v) / (norm() * v.norm()));
}

void Vector3d::randomize()
{
    _x = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    _y = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    _z = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    normalize();
}

void Vector3d::randomize(Vector3d dir, double angle)
{
    double a = (double)(std::rand() % INT_MAX) / (double)INT_MAX * 2 - angle;
    double x = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    double y = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    double z = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    Vector3d v(x, y, z);
    v.normalize();
    v.rotate(dir, a);
    _x = v._x;
    _y = v._y;
    _z = v._z;
}

Vector3d Vector3d::randomized()
{
    double x = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    double y = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    double z = (double)(std::rand() % INT_MAX) / (double)INT_MAX * (std::rand() % 2 ? 1 : -1);
    return Vector3d(x, y, z);
}

void Vector3d::lookAt(Vector3d origin, Vector3d target)
{
    _x = target._x - origin._x;
    _y = target._y - origin._y;
    _z = target._z - origin._z;
    normalize();
}

double &Vector3d::operator[](int index)
{
    if (index == 0)
        return _x;
    if (index == 1)
        return _y;
    if (index == 2)
        return _z;
    return _w;
}

const double &Vector3d::operator[](int index) const
{
    if (index == 0)
        return _x;
    if (index == 1)
        return _y;
    if (index == 2)
        return _z;
    return _w;
}

auto Vector3d::begin()
{
    return &_x;
}

auto Vector3d::begin() const
{
    return &_x;
}

Vector3d Vector3d::operator+(Matrix<double> m)
{
    return Vector3d((double)m[0][0] + _x, m[1][0] + _y, m[2][0] + _z);
}

Vector3d Vector3d::operator-(Matrix<double> m)
{
    return Vector3d(_x - m[0][0], _y - m[1][0], _z - m[2][0]);
}

Vector3d Vector3d::operator*(Matrix<double> m)
{
    return Vector3d(_x * m[0][0], _y * m[1][0], _z * m[2][0]);
}

Vector3d Vector3d::operator%(Matrix<double> m)
{
    return Vector3d(_x * m[0][0], _y * m[1][0], _z * m[2][0]);
}

Vector3d Vector3d::operator^(Matrix<double> m)
{
    return Vector3d(_x * m[0][0], _y * m[1][0], _z * m[2][0]);
}

Vector3d Vector3d::operator|(Matrix<double> m)
{
    return Vector3d(_x * m[0][0], _y * m[1][0], _z * m[2][0]);
}

Vector3d Vector3d::operator+=(Matrix<double> m)
{
    _x += m[0][0];
    _y += m[1][0];
    _z += m[2][0];
    return *this;
}

Vector3d Vector3d::operator-=(Matrix<double> m)
{
    _x -= m[0][0];
    _y -= m[1][0];
    _z -= m[2][0];
    return *this;
}

Vector3d Vector3d::operator*=(Matrix<double> m)
{
    _x *= m[0][0];
    _y *= m[1][0];
    _z *= m[2][0];
    return *this;
}

Vector3d Vector3d::operator%=(Matrix<double> m)
{
    _x *= m[0][0];
    _y *= m[1][0];
    _z *= m[2][0];
    return *this;
}

Vector3d Vector3d::operator^=(Matrix<double> m)
{
    _x *= m[0][0];
    _y *= m[1][0];
    _z *= m[2][0];
    return *this;
}

Vector3d Vector3d::operator|=(Matrix<double> m)
{
    _x *= m[0][0];
    _y *= m[1][0];
    _z *= m[2][0];
    return *this;
}

bool Vector3d::operator==(Matrix<double> m)
{
    return _x == m[0][0] && _y == m[1][0] && _z == m[2][0];
}

bool Vector3d::operator!=(Matrix<double> m)
{
    return _x != m[0][0] || _y != m[1][0] || _z != m[2][0];
}

bool Vector3d::operator<(Matrix<double> m)
{
    return norm() < std::sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
}

bool Vector3d::operator>(Matrix<double> m)
{
    return norm() > std::sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
}

bool Vector3d::operator<=(Matrix<double> m)
{
    return norm() <= std::sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
}

bool Vector3d::operator>=(Matrix<double> m)
{
    return norm() >= std::sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
}

Vector3d Vector3d::operator+(const Vector3d &v)
{
    return Vector3d(_x + v._x, _y + v._y, _z + v._z);
}

Vector3d Vector3d::operator-()
{
    return Vector3d(-_x, -_y, -_z);
}

Vector3d Vector3d::operator-(const Vector3d &v)
{
    return Vector3d(_x - v._x, _y - v._y, _z - v._z);
}

Vector3d Vector3d::operator*(const Vector3d &v)
{
    return Vector3d(_x * v._x, _y * v._y, _z * v._z);
}

Vector3d Vector3d::operator/(const Vector3d &v)
{
    return Vector3d(_x / v._x, _y / v._y, _z / v._z);
}

Vector3d Vector3d::operator*(const double &v)
{
    return Vector3d(_x * v, _y * v, _z * v);
}

Vector3d Vector3d::operator/(const double &v)
{
    return Vector3d(_x / v, _y / v, _z / v);
}

Vector3d Vector3d::operator+=(const Vector3d &v)
{
    _x += v._x;
    _y += v._y;
    _z += v._z;
    return *this;
}

Vector3d Vector3d::operator-=(const Vector3d &v)
{
    _x -= v._x;
    _y -= v._y;
    _z -= v._z;
    return *this;
}

Vector3d Vector3d::operator*=(const Vector3d &v)
{
    _x *= v._x;
    _y *= v._y;
    _z *= v._z;
    return *this;
}

Vector3d Vector3d::operator/=(const Vector3d &v)
{
    _x /= v._x;
    _y /= v._y;
    _z /= v._z;
    return *this;
}

Vector3d Vector3d::operator*=(const double &v)
{
    _x *= v;
    _y *= v;
    _z *= v;
    return *this;
}

Vector3d Vector3d::operator/=(const double &v)
{
    _x /= v;
    _y /= v;
    _z /= v;
    return *this;
}

bool Vector3d::operator==(const Vector3d &v)
{
    return _x == v._x && _y == v._y && _z == v._z;
}

bool Vector3d::operator!=(const Vector3d &v)
{
    return _x != v._x || _y != v._y || _z != v._z;
}

bool Vector3d::operator>(const Vector3d &v)
{
    return this->norm() > std::sqrt(v._x * v._x + v._y * v._y + v._z * v._z);
}

bool Vector3d::operator<(const Vector3d &v)
{
    return this->norm() < std::sqrt(v._x * v._x + v._y * v._y + v._z * v._z);
}

bool Vector3d::operator>=(const Vector3d &v)
{
    return this->norm() >= std::sqrt(v._x * v._x + v._y * v._y + v._z * v._z);
}

bool Vector3d::operator<=(const Vector3d &v)
{
    return this->norm() <= std::sqrt(v._x * v._x + v._y * v._y + v._z * v._z);
}

std::ostream &operator<<(std::ostream &os, const Vector3d &v)
{
    os << "Vector3d(" << v._x << ", " << v._y << ", " << v._z << ")";
    return os;
}

std::istream &operator>>(std::istream &stream, Vector3d &v)
{
    stream >> v._x >> v._y >> v._z;
    return stream;
}