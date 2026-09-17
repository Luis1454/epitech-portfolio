/*
** EPITECH PROJECT, 2024
** Or.cpp
** File description:
** Or
*/

#include "Or.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentOr::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, getPin(1) || getPin(2));
    return getPin(3);
}
