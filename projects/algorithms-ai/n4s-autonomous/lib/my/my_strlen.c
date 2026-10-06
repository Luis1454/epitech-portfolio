/*
** EPITECH PROJECT, 2022
** task03
** File description:
** C pool day 04
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
