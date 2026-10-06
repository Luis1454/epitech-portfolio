/*
** EPITECH PROJECT, 2024
** Paladin.cpp
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(std::string name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << this->_name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->_name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return this->Knight::attack();
}

int Paladin::special()
{
    return this->Enchanter::special();

}

void Paladin::rest()
{
    this->Priest::rest();
}
