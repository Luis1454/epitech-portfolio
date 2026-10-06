/*
** EPITECH PROJECT, 2024
** Afruit.cpp
** File description:
** Afruit
*/

#include "AFruit.hpp"

bool AFruit::isPeeled() const
{
    return _peeled;
}

std::string AFruit::getName() const
{
    return _name;
}

unsigned int AFruit::getVitamins() const
{
    return _vitamins;
}

void AFruit::peel()
{
    _peeled = true;
}