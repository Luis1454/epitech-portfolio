/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "../include/my.h"

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[argc - i - 1]);
        my_putchar('\n');
    }
    return 0;
}
