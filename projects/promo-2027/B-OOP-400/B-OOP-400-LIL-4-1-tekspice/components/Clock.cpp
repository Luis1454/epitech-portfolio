/*
** EPITECH PROJECT, 2024
** Clock.cpp
** File description:
** Clock
*/

#include "Clock.hpp"
#include "../Operators.hpp"

void nts::ComponentClock::setPin(std::size_t pin, nts::Tristate value)
{
    (void)pin;

    if (value == nts::Tristate::Undefined) {
        AComponent::setPin(1, nts::Tristate::Undefined);
        _init = !value;
    } else {
        AComponent::setPin(1, value);
        _init = value == nts::Tristate::True ? 1 : 0;
    }
}

nts::Tristate nts::ComponentClock::compute(std::size_t tick)
{
    bool state = !((_init + tick) % 2);

    if (getPin(1) != nts::Tristate::Undefined)
        AComponent::setPin(1, state ? nts::Tristate::True : nts::Tristate::False);

    return getPin(1);
}
