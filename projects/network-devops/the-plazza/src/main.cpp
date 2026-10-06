/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** main.cpp
*/

#include "../include/Error/Error.hpp"
#include "../include/Parsing/Parsing.hpp"
#include "../include/Reception/Reception.hpp"

int help(void)
{
    std::cout << "USAGE: ./plazza [multiplier] [cooks] [time]" << std::endl;
    std::cout << "\nIn reception:" << std::endl;
    std::cout << "S := TYPE SIZE NUMBER [; TYPE SIZE NUMBER ]*" << std::endl;
    std::cout << "TYPE := [ a .. zA .. Z ]+" << std::endl;
    std::cout << "SIZE := S | M | L | XL | XXL" << std::endl;
    std::cout << "NUMBER := x [1..9][0..9]*" << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    try {
        if (ac == 2 && std::string(av[1]) == "-h")
            return help();
        Parsing parsing;
        parsing.parseArguments(ac, av);
        Reception reception(parsing.getCoockingTime(), parsing.getNumberOfCooks(), parsing.getRestockTime());
        reception.startReception();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}
