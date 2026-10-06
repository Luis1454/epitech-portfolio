/*
** EPITECH PROJECT, 2024
** False.cpp
** File description:
** False
*/

#include "False.hpp"

nts::Tristate nts::ComponentFalse::compute(std::size_t tick)
{
    (void)tick;
    setPin(1, nts::Tristate::False);
    return getPin(1);
}
