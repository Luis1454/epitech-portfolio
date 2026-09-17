/*
** EPITECH PROJECT, 2024
** Parts.cpp
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms()
{
    _serial = "A-01";
    _functional = true;
}

Arms::~Arms(){}

Arms::Arms(std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Arms::isFunctional() const
{
    return _functional;
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functional ? "OK" : "KO")
    << std::endl;
}

Legs::Legs()
{
    _serial = "L-01";
    _functional = true;
}

Legs::~Legs(){}

Legs::Legs(std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Legs::isFunctional() const
{
    return _functional;
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functional ? "OK" : "KO")
    << std::endl;
}

Head::Head()
{
    _serial = "H-01";
    _functional = true;
}

Head::~Head(){}

Head::Head(std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

bool Head::isFunctional() const
{
    return _functional;
}

std::string Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functional ? "OK" : "KO")
    << std::endl;
}
