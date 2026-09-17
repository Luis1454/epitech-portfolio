/*
** EPITECH PROJECT, 2024
** Priest.cpp
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(std::string name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->_name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->checkStatus())
        return;
    std::cout << this->_name << " prays." << std::endl;
    this->_hp = 100;
    this->_power = 100;
}
