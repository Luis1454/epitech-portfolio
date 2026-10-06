/*
** EPITECH PROJECT, 2024
** Strawberry.hpp
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
#define STRAWBERRY_HPP_

#include <iostream>
#include "ABerry.hpp"

class Strawberry : public ABerry {
    public:
        Strawberry(){}
        ~Strawberry(){}
        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "strawberry";
        unsigned int _vitamins = 6;
};

#endif /* !STRAWBERRY_HPP_ */