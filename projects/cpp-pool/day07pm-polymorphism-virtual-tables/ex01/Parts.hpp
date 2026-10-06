/*
** EPITECH PROJECT, 2024
** Parts.hpp
** File description:
** Parts
*/

#include <iostream>

#ifndef PARTS_HPP_
#define PARTS_HPP_

class Arms {
    public:
        Arms();
        ~Arms();
        Arms(std::string &serial, bool functional);
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs();
        ~Legs();
        Legs(std::string &serial, bool functional);
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;

    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head();
        ~Head();
        Head(std::string &serial, bool functional);
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */