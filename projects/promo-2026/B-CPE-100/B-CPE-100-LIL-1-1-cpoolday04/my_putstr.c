/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    while (*str != 0) {
         write(1, &str, 1);
         str++;
    }
    write(1, "\n", 1);
}
