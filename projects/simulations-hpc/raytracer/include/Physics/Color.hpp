/*
** EPITECH PROJECT, 2024
** Color.hpp
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

    #include <vector>
    #include <iostream>
    #include "cmath"

class Color {
    public:
        Color();
        Color(std::string color);
        Color(double r, double g, double b);
        Color(double r, double g, double b, double a);
        ~Color();

        double getR();
        double getG();
        double getB();
        double getA();

        void setR(double r);
        void setG(double g);
        void setB(double b);
        void setA(double a);

        void normalize();
        void reverse();
        void clamp();
        Color clamped();

        Color lowCut();
        Color highCut();

        virtual void setColor(double r, double g, double b);
        virtual void setColor(Color color);
        virtual void subColor(double r, double g, double b);
        virtual void subColor(Color color);
        virtual Color getColor();

        Color operator+(Color color);
        Color operator-(Color color);
        Color operator*(Color color);
        Color operator*(double value);
        Color operator/(Color color);
        Color operator/(double value);
        Color operator+=(Color color);
        Color operator-=(Color color);
        Color operator*=(Color color);
        Color operator*=(double value);
        Color operator/=(Color color);
        Color operator/=(double value);
        bool operator==(Color color);
        bool operator!=(Color color);
        bool operator<(Color color);
        bool operator>(Color color);
        bool operator<=(Color color);
        bool operator>=(Color color);

        friend std::ostream &operator<<(std::ostream &os, const Color &v);
        friend std::istream &operator>>(std::istream &is, Color &v);

    protected:
        double _r;
        double _g;
        double _b;
        double _a;
};

typedef std::vector<std::vector<Color>> Image;

#endif /* !COLOR_HPP_ */
