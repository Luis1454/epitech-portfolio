/*
** EPITECH PROJECT, 2024
** Pre4008.cpp
** File description:
** Pre4008
*/

#include "Pre4008.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4008::compute(std::size_t tick)
{
    (void)tick;

    int a = 0;
    int b = 0;
    int sum = 0;

    a += getPin(9) == nts::Tristate::True ? 16 : 0;
    a += getPin(6) == nts::Tristate::True ? 8 : 0;
    a += getPin(4) == nts::Tristate::True ? 4 : 0;
    a += getPin(2) == nts::Tristate::True ? 2 : 0;
    a += getPin(15) == nts::Tristate::True ? 1 : 0;

    b += getPin(7) == nts::Tristate::True ? 8 : 0;
    b += getPin(5) == nts::Tristate::True ? 4 : 0;
    b += getPin(3) == nts::Tristate::True ? 2 : 0;
    b += getPin(1) == nts::Tristate::True ? 1 : 0;

    sum = a + b;

    setPin(10, (sum & 1) ? nts::Tristate::True : nts::Tristate::False);
    setPin(11, (sum & 2) ? nts::Tristate::True : nts::Tristate::False);
    setPin(12, (sum & 4) ? nts::Tristate::True : nts::Tristate::False);
    setPin(13, (sum & 8) ? nts::Tristate::True : nts::Tristate::False);
    setPin(14, (sum & 16) ? nts::Tristate::True : nts::Tristate::False);

    return getPin(14);
}
