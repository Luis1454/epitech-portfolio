/*
** EPITECH PROJECT, 2024
** MyCat.cpp
** File description:
** day 06
*/

#include <iostream>
#include <fstream>

int read_files(int ac, char **av)
{
    std::string line;
    std::ifstream file;

    for (int i = 1; i < ac; i++) {
        file.open(av[i]);
        if (!file.is_open()) {
            std::cerr << "MyCat: " << av[i] << ": No such file or directory" << std::endl;
            return 84;
        }
        while (std::getline(file, line))
            std::cout << line << std::endl;
        file.close();
    }
    return 0;
}

int read_input()
{
    std::string line;

    while (std::getline(std::cin, line))
        std::cout << line << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    std::string line;

    return ac == 1 ? read_input() : read_files(ac, av);
}
