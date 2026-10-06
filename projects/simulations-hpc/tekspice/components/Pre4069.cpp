/*
** EPITECH PROJECT, 2024
** Pre4069.cpp
** File description:
** Pre4069
*/

#include "Pre4069.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4069::compute(std::size_t tick)
{
    (void)tick;

    setPin(2, !getPin(1));
    setPin(4, !getPin(3));
    setPin(6, !getPin(5));
    setPin(8, !getPin(9));
    setPin(10, !getPin(11));
    setPin(12, !getPin(13));

    return getPin(2);
}
