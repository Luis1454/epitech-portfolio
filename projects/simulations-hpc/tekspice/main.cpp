/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/


#include <cstddef>
#include <iostream>
#include "Factory.hpp"
#include "Cmd.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    try {
        nts::Cmd cmd(av[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
