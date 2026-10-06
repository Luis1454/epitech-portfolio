/*
** EPITECH PROJECT, 2022
** my_print_revalpha.c
** File description:
** print the reversed alphabet
*/

#include <unistd.h>

int my_print_revalpha(void)
{
    char c[1] = "z";

    for (; c[0] >= 'a'; c[0]--)
        write(1, c, 1);
    write(1, "\n", 1);

    return 0;
}
