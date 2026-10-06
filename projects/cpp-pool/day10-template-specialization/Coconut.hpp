/*
** EPITECH PROJECT, 2024
** Coconut.hpp
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include <iostream>
#include "ANut.hpp"

class Coconut : public ANut {
    public:
        Coconut(){}
        ~Coconut(){}

        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "coconut";
        unsigned int _vitamins = 4;
};

#endif /* !COCONUT_HPP_ */
