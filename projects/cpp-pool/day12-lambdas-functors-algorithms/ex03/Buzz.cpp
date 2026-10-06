/*
** EPITECH PROJECT, 2024
** Buzz.cpp
** File description:
** Buzz
*/

#include "Buzz.hpp"

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
}