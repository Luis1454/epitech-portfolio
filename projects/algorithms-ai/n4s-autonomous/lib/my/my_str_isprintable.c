/*
** EPITECH PROJECT, 2022
** task 14
** File description:
** C pool day 06
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            return 0;
        i += 1;
    }
    return 1;
}
