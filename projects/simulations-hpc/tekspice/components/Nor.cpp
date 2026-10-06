/*
** EPITECH PROJECT, 2024
** Nor.cpp
** File description:
** Nor
*/

#include "Nor.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentNor::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, !(getPin(1) || getPin(2)));
    return getPin(3);
}
