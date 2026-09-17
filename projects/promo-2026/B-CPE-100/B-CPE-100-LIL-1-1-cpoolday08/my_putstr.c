/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

char my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int cnt = 0;

    while (str[cnt] != 0) {
        my_putchar(str[cnt]);
        cnt++;
    }
    my_putchar('\n');
}
