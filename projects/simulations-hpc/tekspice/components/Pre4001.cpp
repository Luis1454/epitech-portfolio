/*
** EPITECH PROJECT, 2024
** 4001.cpp
** File description:
** 4001
*/

#include "Pre4001.hpp"
#include "../Operators.hpp"

nts::Tristate nts::Component4001::compute(std::size_t pin) {
    setPin(3, !(getPin(1) || getPin(2)));
    setPin(4, !(getPin(5) || getPin(6)));
    setPin(10, !(getPin(8) || getPin(9)));
    setPin(11, !(getPin(12) || getPin(13)));

    return getPin(3);
}
