/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** task03 Day04
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
