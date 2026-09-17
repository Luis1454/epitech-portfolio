/*
** EPITECH PROJECT, 2024
** Buzz.hpp
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &file = "buzz.txt") : Toy(BUZZ, name, file){}
        ~Buzz(){}
};

#endif /* !BUZZ_HPP_ */
