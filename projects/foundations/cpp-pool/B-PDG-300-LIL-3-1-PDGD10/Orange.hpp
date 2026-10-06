/*
** EPITECH PROJECT, 2024
** Orange.hpp
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
#define ORANGE_HPP_

#include <iostream>
#include "ACitrus.hpp"

class Orange : public ACitrus {
    public:
        Orange(){}
        ~Orange(){}

        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "orange";
        unsigned int _vitamins = 7;
};

#endif /* !ORANGE_HPP_ */
