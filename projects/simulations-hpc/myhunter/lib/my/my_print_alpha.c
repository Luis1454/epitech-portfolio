/*
** EPITECH PROJECT, 2022
** my_print_alpha.c
** File description:
** print the alphabet
*/

#include <unistd.h>

int my_print_alpha(void)
{
    char c[1] = "a";

    for (; c[0] <= 'z'; c[0]++)
        write(1, c, 1);
    write(1, "\n", 1);

    return 0;
}
