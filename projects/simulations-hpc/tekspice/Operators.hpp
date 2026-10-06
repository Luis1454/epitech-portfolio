/*
** EPITECH PROJECT, 2024
** Operators.hpp
** File description:
** Operators
*/

#ifndef OPERATORS_HPP_
#define OPERATORS_HPP_

#include "Factory.hpp"

nts::Tristate operator!(nts::Tristate const &a);

nts::Tristate operator&&(nts::Tristate const &a, nts::Tristate const &b);

nts::Tristate operator||(nts::Tristate const &a, nts::Tristate const &b);

nts::Tristate operator^(nts::Tristate const &a, nts::Tristate const &b);

#endif /* !OPERATORS_HPP_ */
