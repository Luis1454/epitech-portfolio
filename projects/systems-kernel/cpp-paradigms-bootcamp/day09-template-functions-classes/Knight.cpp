/*
** EPITECH PROJECT, 2024
** Knight.cpp
** File description:
** Knight
*/

#include "Knight.hpp"
#include "Peasant.hpp"

Knight::Knight(std::string name, int power) : Peasant(name, power)
{
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;

}

Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->checkStatus())
        return 0;
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->_name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (this->checkStatus())
        return 0;
    if (this->_power < 30) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    this->_power -= 30;
    std::cout << this->_name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (this->checkStatus())
        return;
    std::cout << this->_name << " eats." << std::endl;
    this->_power += 50;
    this->_power = (this->_power > 100) ? 100 : this->_power;
    return;
}
