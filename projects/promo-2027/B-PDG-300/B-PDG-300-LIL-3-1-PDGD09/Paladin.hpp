/*
** EPITECH PROJECT, 2024
** Paladin.hpp
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Peasant, virtual public Knight, virtual public Enchanter, virtual public Priest {
    public:
        Paladin(std::string name, int power);
        ~Paladin();
        int attack();
        int special();
        void rest();
};

#endif /* !PALADIN_HPP_ */
