/*
** EPITECH PROJECT, 2022
** print
** File description:
** print and cmp
*/

#include "./myprint.h"
#include <stdarg.h>

void my_alpha(va_list *list)
{
    char *str = va_arg((*list), char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123) {
            my_putchar((str[i] - 32));
        } else {
            my_putchar(str[i]);
        }
    }
}

int cmp(char a, char b, char *c)
{
    if (c[0] == a && c[1] == b) {
        return 0;
    } else {
        return 1;
    }
}
