/*
** EPITECH PROJECT, 2024
** ACitrus.hpp
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
#define ACITRUS_HPP_

#include "AFruit.hpp"

class ACitrus : public AFruit {
    public:
        ACitrus(){}
        ~ACitrus(){}

    protected:
        bool _peeled = false;
};

#endif /* !ACITRUS_HPP_ */
