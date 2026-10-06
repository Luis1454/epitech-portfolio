/*
** EPITECH PROJECT, 2024
** Color.cpp
** File description:
** Color
*/

#include "../../include/Physics/Color.hpp"

Color::Color()
{
    _r = 0.0;
    _g = 0.0;
    _b = 0.0;
    _a = 1.0;
}

Color::~Color()
{
}

Color::Color(std::string color)
{
    if (color == "red")
        _r = 1.0;
    else if (color == "green")
        _g = 1.0;
    else if (color == "blue")
        _b = 1.0;
    else if (color == "yellow") {
        _r = 1.0;
        _g = 1.0;
    } else if (color == "cyan") {
        _g = 1.0;
        _b = 1.0;
    } else if (color == "magenta") {
        _r = 1.0;
        _b = 1.0;
    } else if (color == "white") {
        _r = 1.0;
        _g = 1.0;
        _b = 1.0;
    } else if (color == "black") {
        _r = 0.0;
        _g = 0.0;
        _b = 0.0;
    } else
        throw std::invalid_argument("Invalid color");
}

Color::Color(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
    _a = 1.0;
}

Color::Color(double r, double g, double b, double a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

void Color::setColor(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
    _a = 1.0;
}

void Color::setColor(Color color)
{
    _r = color.getR();
    _g = color.getG();
    _b = color.getB();
    _a = color.getA();
}

Color Color::lowCut()
{
    return Color(std::max(0.0, _r), std::max(0.0, _g), std::max(0.0, _b));
}

Color Color::highCut()
{
    return Color(std::min(1.0, _r), std::min(1.0, _g), std::min(1.0, _b));
}

void Color::subColor(double r, double g, double b)
{
    _r *= r;
    _g *= g;
    _b *= b;
}

void Color::subColor(Color color)
{
    _r *= color.getR();
    _g *= color.getG();
    _b *= color.getB();
    _a *= color.getA();
}

Color Color::getColor()
{
    return Color(_r, _g, _b, _a);
}

double Color::getR()
{
    return _r;
}

double Color::getG()
{
    return _g;
}

double Color::getB()
{
    return _b;
}

double Color::getA()
{
    return _a;
}

void Color::setR(double r)
{
    _r = r;
}

void Color::setG(double g)
{
    _g = g;
}

void Color::setB(double b)
{
    _b = b;
}

void Color::setA(double a)
{
    _a = a;
}

void Color::normalize()
{
    double norm = std::sqrt(_r * _r + _g * _g + _b * _b);

    _r /= norm;
    _g /= norm;
    _b /= norm;
}

void Color::reverse()
{
    _r = 1.0 - _r;
    _g = 1.0 - _g;
    _b = 1.0 - _b;
}

void Color::clamp()
{
    double overflow = (_r + _g + _b) - 3.0;

    overflow = std::max(0.0, overflow);
    _r = std::min(1.0, std::max(0.0, _r + overflow / 3.0));
    _g = std::min(1.0, std::max(0.0, _g + overflow / 3.0));
    _b = std::min(1.0, std::max(0.0, _b + overflow / 3.0));
    _a = std::min(1.0, std::max(0.0, _a));
}

Color Color::clamped()
{
    Color c = Color(_r, _g, _b, _a);

    c.clamp();
    return c;
}

Color Color::operator+(Color color)
{
    return Color(_r + color.getR(), _g + color.getG(), _b + color.getB());
}

Color Color::operator-(Color color)
{
    return Color(_r - color.getR(), _g - color.getG(), _b - color.getB());
}

Color Color::operator*(Color color)
{
    return Color(_r * color.getR(), _g * color.getG(), _b * color.getB());
}

Color Color::operator*(double value)
{
    return Color(_r * value, _g * value, _b * value);
}

Color Color::operator/(Color color)
{
    return Color(_r / color.getR(), _g / color.getG(), _b / color.getB());
}

Color Color::operator/(double value)
{
    return Color(_r / value, _g / value, _b / value);
}

Color Color::operator+=(Color color)
{
    _r += color.getR() * _a * color.getA();
    _g += color.getG() * _a * color.getA();
    _b += color.getB() * _a * color.getA();
    return *this;
}

Color Color::operator-=(Color color)
{
    _r -= color.getR() * _a * color.getA();
    _g -= color.getG() * _a * color.getA();
    _b -= color.getB() * _a * color.getA();
    return *this;
}

Color Color::operator*=(Color color)
{
    _r *= color.getR() * color.getA();
    _g *= color.getG() * color.getA();
    _b *= color.getB() * color.getA();
    return *this;
}

Color Color::operator*=(double value)
{
    _r *= value;
    _g *= value;
    _b *= value;
    return *this;
}

Color Color::operator/=(Color color)
{
    _r /= color.getR() * _a * color.getA();
    _g /= color.getG() * _a * color.getA();
    _b /= color.getB() * _a * color.getA();
    return *this;
}

Color Color::operator/=(double value)
{
    _r /= value;
    _g /= value;
    _b /= value;
    return *this;
}

bool Color::operator==(Color color)
{
    return _r == color.getR() && _g == color.getG() && _b == color.getB();
}

bool Color::operator!=(Color color)
{
    return _r != color.getR() || _g != color.getG() || _b != color.getB();
}

bool Color::operator<(Color color)
{
    double a = std::sqrt(_r * _r + _g * _g + _b * _b);
    double b = std::sqrt(color.getR() * color.getR() + color.getG() * color.getG() + color.getB() * color.getB());

    return a < b;
}

bool Color::operator>(Color color)
{
    double a = std::sqrt(_r * _r + _g * _g + _b * _b);
    double b = std::sqrt(color.getR() * color.getR() + color.getG() * color.getG() + color.getB() * color.getB());

    return a > b;
}

bool Color::operator<=(Color color)
{
    double a = std::sqrt(_r * _r + _g * _g + _b * _b);
    double b = std::sqrt(color.getR() * color.getR() + color.getG() * color.getG() + color.getB() * color.getB());

    return a <= b;
}

bool Color::operator>=(Color color)
{
    double a = std::sqrt(_r * _r + _g * _g + _b * _b);
    double b = std::sqrt(color.getR() * color.getR() + color.getG() * color.getG() + color.getB() * color.getB());

    return a >= b;
}

std::ostream &operator<<(std::ostream &os, const Color &v)
{
    os << "Color(" << v._r << ", " << v._g << ", " << v._b << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Color &v)
{
    is >> v._r >> v._g >> v._b;
    return is;
}
