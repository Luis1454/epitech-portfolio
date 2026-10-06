/*
** EPITECH PROJECT, 2023
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** main.c
*/

#include "include/parser.h"
#include "include/process.h"

int main(int ac, char **av)
{
    if (parser(ac, av) == 84)
        return (84);
    return process(av);
}
