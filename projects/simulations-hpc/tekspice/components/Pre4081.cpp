/*
** EPITECH PROJECT, 2024
** Pre4081.cpp
** File description:
** Pre4081
*/

#include "Pre4081.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4081::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, getPin(1) && getPin(2));
    setPin(4, getPin(5) && getPin(6));
    setPin(10, getPin(8) && getPin(9));
    setPin(11, getPin(12) && getPin(13));

    return getPin(3);
}
