/*
** EPITECH PROJECT, 2024
** Priest.hpp
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : virtual public Peasant, virtual public Enchanter {
    public:
        Priest(std::string name, int power);
        ~Priest();
        void rest();
};

#endif /* !PRIEST_HPP_ */
