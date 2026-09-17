/*
** EPITECH PROJECT, 2024
** ANut
** File description:
** ANut
*/

#ifndef ANUT_HPP_
#define ANUT_HPP_

#include <iostream>
#include "AFruit.hpp"

class ANut : public AFruit {
    public:
        ANut(){}
        ~ANut(){}

    protected:
        bool _peeled = false;
};

#endif /* !ANUT_HPP_ */
