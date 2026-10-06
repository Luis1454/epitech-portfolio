/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** duplicate a string
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"

char *my_strdup(char const *src)
{
    char *out = NULL;
    if (!src)
        return NULL;
    out = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (int i = 0; src[i]; i++)
        out[i] = src[i];
    out[my_strlen(src)] = 0;
    return out;
}

char *my_strdup_up(char const *src, int up)
{
    int size = MAX(my_strlen(src), up) + 1;
    char *out = malloc(sizeof(char) * size + 1);

    out[size] = 0;
    for (int i = 0; src[i]; i++)
        out[i] = src[i];
    for (int i = my_strlen(src); i < size; i++)
        out[i] = 0;
    return out;
}
