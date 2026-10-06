/*
** EPITECH PROJECT, 2024
** Not.cpp
** File description:
** Not
*/

#include "Not.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentNot::compute(std::size_t tick)
{
    (void)tick;

    setPin(2, !getPin(1));
    return getPin(2);
}
