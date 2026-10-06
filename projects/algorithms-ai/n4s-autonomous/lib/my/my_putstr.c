/*
** EPITECH PROJECT, 2022
** task02
** File description:
** C pool day 04
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        putchar_error(str[i]);
        i++;
    }
    return 0;
}
