/*
** EPITECH PROJECT, 2024
** True.cpp
** File description:
** True
*/

#include "True.hpp"

nts::Tristate nts::ComponentTrue::compute(std::size_t tick)
{
    (void)tick;
    setPin(1, nts::Tristate::True);
    return getPin(1);
}
