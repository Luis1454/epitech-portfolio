/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** Parser
*/

#include "include/Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

int displayHelp()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./arcade ./lib/arcade_*.so" << std::endl;
    std::cout << "To see more information, check the Documentation_arcade.pdf file in /doc folder" << std::endl;
    return 1;
}

int Parser::parse(int ac, char **av)
{
    if (ac < 2 || ac > 2)
        throw err::NotEnoughArguments();
    if (std::string(av[1]) == "-h")
        return displayHelp();
    if (!std::ifstream(av[1]).good())
        throw err::NoFileFound();
    if (std::string(av[1]).substr(std::string(av[1]).find_last_of(".") + 1) != "so")
        throw err::ErrorSoFile();
    if (std::string(av[1]).find("arcade_") == std::string::npos
    || std::string(av[1]).substr(std::string(av[1]).find_last_of("/") + 1) == "arcade_.so")
        throw err::NotValidSoFile();
    return 0;
}
