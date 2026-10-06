/*
** EPITECH PROJECT, 2024
** Operators.cpp
** File description:
** Operators
*/

#include "Operators.hpp"

nts::Tristate operator!(nts::Tristate const &a) {
    if (a == nts::True)
        return nts::False;
    if (a == nts::False)
        return nts::True;
    return nts::Undefined;
}

nts::Tristate operator&&(nts::Tristate const &a, nts::Tristate const &b) {
    if (a == nts::True && b == nts::True)
        return nts::True;
    if (a == nts::False || b == nts::False)
        return nts::False;
    return nts::Undefined;
}

nts::Tristate operator||(nts::Tristate const &a, nts::Tristate const &b) {
    if (a == nts::True || b == nts::True)
        return nts::True;
    if (a == nts::False && b == nts::False)
        return nts::False;
    return nts::Undefined;
}

nts::Tristate operator^(nts::Tristate const &a, nts::Tristate const &b) {
    if (a == nts::True && b == nts::False)
        return nts::True;
    if (a == nts::False && b == nts::True)
        return nts::True;
    if (a == nts::True && b == nts::True)
        return nts::False;
    if (a == nts::False && b == nts::False)
        return nts::False;
    return nts::Undefined;
}
