/*
** EPITECH PROJECT, 2024
** Almond.hpp
** File description:
** Almond
*/

#ifndef ALMOND_HPP_
#define ALMOND_HPP_

#include <iostream>
#include "ANut.hpp"

class Almond : public ANut {
    public:
        Almond(){}
        ~Almond(){}
        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}

    protected:
        std::string _name = "almond";
        unsigned int _vitamins = 2;
};

#endif /* !ALMOND_HPP_ */
