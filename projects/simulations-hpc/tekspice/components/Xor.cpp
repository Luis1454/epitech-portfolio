/*
** EPITECH PROJECT, 2024
** Xor.cpp
** File description:
** Xor
*/

#include "Xor.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentXor::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, getPin(1) ^ getPin(2));
    return getPin(3);
}
