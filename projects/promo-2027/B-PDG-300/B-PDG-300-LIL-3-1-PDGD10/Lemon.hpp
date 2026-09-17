/*
** EPITECH PROJECT, 2024
** Lemon.hpp
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include <iostream>
#include "ACitrus.hpp"

class Lemon : public ACitrus {
    public:
        Lemon(){}
        ~Lemon(){}
        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "lemon";
        unsigned int _vitamins = 4;
};

#endif /* !LEMON_HPP_ */
