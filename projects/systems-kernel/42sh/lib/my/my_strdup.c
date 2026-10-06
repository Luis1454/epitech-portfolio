/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** duplicate a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup_f(char *dest, char const *src)
{
    if (dest)
        free(dest);
    if (!src)
        return NULL;

    char *out = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int i = 0; src[i]; i++)
        out[i] = src[i];
    out[my_strlen(src)] = 0;
    return out;
}

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
