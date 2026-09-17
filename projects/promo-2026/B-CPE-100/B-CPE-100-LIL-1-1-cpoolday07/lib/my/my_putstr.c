/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    while (!(*str)) {
         write(1, &str, 1);
         str++;
    }
    write(1, "\n", 1);

    return 0;
}
