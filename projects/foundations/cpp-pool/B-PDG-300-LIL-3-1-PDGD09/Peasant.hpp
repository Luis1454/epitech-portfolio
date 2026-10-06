/*
** EPITECH PROJECT, 2024
** Peasant.hpp
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <iostream>
#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();

        std::string getName() const;
        int getPower() const;
        int getHp() const;

        int attack();
        int special();

        void rest();
        void damage(int damage);

        bool checkStatus();

    protected:
        std::string _name;
        int _power;
        int _hp;
};

#endif /* !PEASANT_HPP_ */
