/*
** EPITECH PROJECT, 2024
** Enchanter.cpp
** File description:
** Enchanter
*/

#include <iostream>
#include "Enchanter.hpp"

Enchanter::Enchanter(std::string name, int power) : Peasant(name, power)
{
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (this->checkStatus())
        return 0;
    std::cout << this->_name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (this->checkStatus())
        return 0;
    if (this->_power < 50) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    this->_power -= 50;
    std::cout << this->_name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (this->checkStatus())
        return;
    std::cout << this->_name << " meditates." << std::endl;
    this->_power += 100;
    this->_power = (this->_power > 100) ? 100 : this->_power;
}
