/*
** EPITECH PROJECT, 2024
** Output.cpp
** File description:
** Output
*/

#include "Output.hpp"

nts::Tristate nts::ComponentOutput::compute(std::size_t tick)
{
    (void)tick;
    return getPin(1);
}
