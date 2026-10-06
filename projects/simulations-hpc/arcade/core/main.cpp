/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** main
*/

#include "include/Core.hpp"
#include "include/Parser.hpp"

int main(int ac, char **av)
{
    try {
        Parser parser;
        arc::ICore core;
        std::unique_ptr<IDisplayModule> displayModule;

        if (parser.parse(ac, av) == 1)
            return 0;
        displayModule = core.openGraphical(av[1], std::move(displayModule));
        if (displayModule == nullptr)
            return 84;
        core.mainloop(std::move(displayModule));
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "USAGE" << std::endl;
        std::cerr << "    ./arcade ./lib/arcade_*.so" << std::endl;
        return 84;
    }
}
