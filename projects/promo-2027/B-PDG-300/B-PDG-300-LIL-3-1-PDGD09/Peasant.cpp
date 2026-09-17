/*
** EPITECH PROJECT, 2024
** Peasant.cpp
** File description:
** Peasant
*/

#include "Peasant.hpp"

bool Peasant::checkStatus()
{
    if (this->_hp <= 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    return this->_hp <= 0;
}

void Peasant::damage(int damage)
{
    this->_hp -= damage;
    this->_hp = (this->_hp < 0) ? 0 : this->_hp;
    if (this->checkStatus())
        return;
    std::cout << this->_name << " takes " << damage << " damage." << std::endl;
}

void Peasant::rest()
{
    if (this->checkStatus())
        return;
    std::cout << this->_name << " takes a nap." << std::endl;
    this->_power += 30;
    this->_power = (this->_power > 100) ? 100 : this->_power;
}

int Peasant::special()
{
    if (this->checkStatus())
        return 0;
    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

int Peasant::attack()
{
    if (this->checkStatus())
        return 0;
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->_name << " tosses a stone." << std::endl;
    return 5;
}

std::string Peasant::getName() const
{
    return this->_name;
}

int Peasant::getPower() const
{
    return this->_power;
}

int Peasant::getHp() const
{
    return this->_hp;
}

Peasant::Peasant(const std::string &name, int power)
{
    this->_hp = 100;
    this->_name = name;
    this->_power = power;
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}
