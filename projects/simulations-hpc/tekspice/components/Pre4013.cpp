/*
** EPITECH PROJECT, 2024
** Pre4013.cpp
** File description:
** Pre4013
*/

#include "Pre4013.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4013::compute(std::size_t tick)
{
    (void)tick;

    if (getPin(6) == nts::Tristate::True)
        setPin(1, nts::Tristate::True);
    if (getPin(8) == nts::Tristate::True)
        setPin(1, nts::Tristate::True);
    if (getPin(4) == nts::Tristate::True)
        setPin(1, nts::Tristate::False);
    if (getPin(10) == nts::Tristate::True)
        setPin(1, nts::Tristate::False);

    setPin(1, getPin(5) ^ getPin(3));
    setPin(2, !getPin(1));

    setPin(13, getPin(9) ^ getPin(11));
    setPin(12, !getPin(13));
    return getPin(1);
}
