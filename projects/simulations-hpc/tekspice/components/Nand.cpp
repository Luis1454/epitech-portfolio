/*
** EPITECH PROJECT, 2024
** Nand.cpp
** File description:
** Nand
*/

#include "Nand.hpp"
#include "../Operators.hpp"

nts::Tristate nts::ComponentNand::compute(std::size_t tick)
{
    (void)tick;

    setPin(3, !(getPin(1) && getPin(2)));
    return getPin(3);
}
