/*
** EPITECH PROJECT, 2024
** Raspberry.hpp
** File description:
** Raspberry
*/

#ifndef RASPBERRY_HPP_
#define RASPBERRY_HPP_

#include <iostream>
#include "ABerry.hpp"

class Raspberry : public ABerry {
    public:
        Raspberry(){}
        ~Raspberry(){}

        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return _peeled ? _vitamins : 0;}
        bool isPeeled() const {return _peeled;}
        void peel() {_peeled = true;}        

    protected:
        std::string _name = "raspberry";
        unsigned int _vitamins = 5;
};

#endif /* !RASPBERRY_HPP_ */
