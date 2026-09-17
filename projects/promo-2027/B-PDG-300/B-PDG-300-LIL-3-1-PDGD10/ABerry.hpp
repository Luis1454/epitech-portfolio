/*
** EPITECH PROJECT, 2024
** ABerry.hpp
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
#define ABERRY_HPP_

#include "AFruit.hpp"

class ABerry : public AFruit {
    public:
        ABerry(){}
        ~ABerry(){}

    protected:
        bool _peeled = true;
};

#endif /* !ABERRY_HPP_ */
