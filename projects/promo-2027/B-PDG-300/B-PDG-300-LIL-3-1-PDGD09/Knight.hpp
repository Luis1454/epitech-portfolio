/*
** EPITECH PROJECT, 2024
** Knight.hpp
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(std::string name, int power);
        ~Knight();
        int attack();
        int special();
        void rest();
};

#endif /* !KNIGHT_HPP_ */
