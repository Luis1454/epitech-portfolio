/*
** EPITECH PROJECT, 2024
** And.cpp
** File description:
** And
*/

#include "And.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentAnd::compute(std::size_t tick)
{
    (void)tick;
    setPin(3, getPin(1) && getPin(2));
    return getPin(3);
}
