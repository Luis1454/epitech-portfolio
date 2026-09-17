/*
** EPITECH PROJECT, 2024
** Xnor.cpp
** File description:
** Xnor
*/

#include "Xnor.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentXnor::compute(std::size_t tick)
{
    (void)tick;
    setPin(3, !(getPin(1) ^ getPin(2)));
    return getPin(3);
}
