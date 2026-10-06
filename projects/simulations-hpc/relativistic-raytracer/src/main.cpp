/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** main.cpp
*/

#include "../include/RayTracer.hpp"
#include "../include/Parser/Parser.hpp"

void displayHelp()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "    ./raytracer <-sfml> <SCENE_FILE>" << std::endl;
    std::cout << "SCENE_FILE: scene configuration" << std::endl;
}

int main(int ac, char **av)
{
    try {
        RayTracer raytracer;
        Parser info;
        int sfml = 0;

        if (ac == 2 && (std::string(av[1]) == "--help" || std::string(av[1]) == "-h")) {
            displayHelp();
            return 0;
        }

        if (ac >= 2 && (std::string(av[1]) == "-sfml")) {
            sfml = 1;
            if (ac == 2) {
                std::cerr << "Error: No scene file provided" << std::endl;
                return 84;
            }
            if (!info.parser(ac - 1, av + 1))
                return 84;
        } else if (!info.parser(ac, av))
            return 84;

        raytracer.initRayTracer(info, sfml);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
