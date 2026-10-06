/*
** EPITECH PROJECT, 2024
** AFruit.cpp
** File description:
** Afruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_

#include <iostream>
#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        AFruit(){}
        ~AFruit(){}

        std::string getName() const;
        unsigned int getVitamins() const;
        bool isPeeled() const;
        void peel();

    protected:
        std::string _name;
        unsigned int _vitamins;
        bool _peeled;
};

#endif /* !AFRUIT_HPP_ */
