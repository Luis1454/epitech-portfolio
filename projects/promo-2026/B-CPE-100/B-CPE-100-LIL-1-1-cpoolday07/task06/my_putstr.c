/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != 0) {
         my_putchar(*str);
         str++;
    }
    my_putchar('\n');

    return 0;
}
