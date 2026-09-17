/*
** EPITECH PROJECT, 2024
** Woody.hpp
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include <iostream>
#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &file = "woody.txt") : Toy(WOODY, name, file){}
        ~Woody(){}
};

#endif /* !WOODY_HPP_ */
