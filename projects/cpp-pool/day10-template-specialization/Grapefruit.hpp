/*
** EPITECH PROJECT, 2024
** Grapefruit.hpp
** File description:
** Grapefruit
*/

#ifndef GRAPEFRUIT_HPP_
#define GRAPEFRUIT_HPP_

#include <iostream>
#include "ACitrus.hpp"

class Grapefruit : public ACitrus {
    public:
        Grapefruit(){}
        ~Grapefruit(){}

        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "grapefruit";
        unsigned int _vitamins = 5;
};
#endif /* !GRAPEFRUIT_HPP_ */
