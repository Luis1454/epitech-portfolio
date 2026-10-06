/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

int main(int ac, char **av)
{
    if (ac != 1 && !av[1])
        return 84;
    return init_game();
}
