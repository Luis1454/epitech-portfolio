/*
** EPITECH PROJECT, 2022
** my_strndup.c
** File description:
** my_strndup function
*/

#include <stdlib.h>
#include "../../include/my_macro_abs.h"

int my_strlen(const char *str);

char *my_strndup(const char *str, int n)
{
    int i = 0;
    char *new = NULL;

    if (str == NULL)
        return NULL;
    new = malloc(sizeof(char) * (MIN(my_strlen(str), n) + 1));
    if (new == NULL)
        return NULL;
    for (; str[i] && i < n; i++)
        new[i] = str[i];
    new[i] = 0;
    return new;
}
