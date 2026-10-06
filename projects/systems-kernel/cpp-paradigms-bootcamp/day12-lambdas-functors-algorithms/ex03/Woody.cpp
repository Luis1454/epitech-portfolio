/*
** EPITECH PROJECT, 2024
** Woody.cpp
** File description:
** Woody
*/

#include "Woody.hpp"

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}
