/*
** EPITECH PROJECT, 2024
** Enchanter.hpp
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"
#include "Knight.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(std::string name, int power);
        ~Enchanter();
        int attack();
        int special();
        void rest();
};

#endif /* !ENCHANTER_HPP_ */
