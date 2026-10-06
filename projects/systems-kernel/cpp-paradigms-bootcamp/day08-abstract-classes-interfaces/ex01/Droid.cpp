/*
** EPITECH PROJECT, 2024
** Droid.cpp
** File description:
** Droid
*/

#include <iostream>
#include "Droid.hpp"

Droid::Droid(std::string Id)
{
    this->_id = Id;
    this->_energy = 50;
    this->_attack = 25;
    this->_toughness = 15;
    this->_status = new std::string("Standing by");
    this->_battleData = new DroidMemory();
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    this->_attack = droid._attack;
    this->_toughness = droid._toughness;
    this->_status = droid._status;
    this->_battleData = droid._battleData;
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(){
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
    delete this->_status;
    delete this->_battleData;
}

std::string Droid::getId() const
{
    return (this->_id);
}

size_t Droid::getEnergy() const
{
    return (this->_energy);
}

size_t Droid::getAttack() const
{
    return (this->_attack);
}

size_t Droid::getToughness() const
{
    return (this->_toughness);
}

std::string *Droid::getStatus() const
{
    return (this->_status);
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->_status = status;
}

Droid &Droid::operator=(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    this->_status = droid._status;
    return *this;
}

bool Droid::operator==(const Droid &droid) const
{
    return this->_status == droid._status ? true : false;
}

bool Droid::operator!=(const Droid &droid) const
{
    return this->_status != droid._status ? true : false;
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t loss = 100 - this->_energy;

    if (energy >= loss) {
        this->_energy = 100;
        energy -= loss;
    } else {
        this->_energy += energy;
        energy = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid)
{
    stream << "Droid '" << droid.getId() << "', " <<
    *droid.getStatus() << ", " << droid.getEnergy();
    return stream;
}
