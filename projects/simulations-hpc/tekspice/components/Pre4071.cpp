/*
** EPITECH PROJECT, 2024
** Pre4071.cpp
** File description:
** Pre4071
*/

#include "Pre4071.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4071::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, getPin(1) || getPin(2));
    setPin(4, getPin(5) || getPin(6));
    setPin(10, getPin(8) || getPin(9));
    setPin(11, getPin(12) || getPin(13));

    return getPin(3);
}
