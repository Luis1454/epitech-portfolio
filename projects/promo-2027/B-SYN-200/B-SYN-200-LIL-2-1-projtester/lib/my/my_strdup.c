/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** duplicate a string
*/

#include "../../include/my.h"

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

char *my_strndup(char const *src, int n)
{
    char *out = NULL;

    if (!src)
        return NULL;
    out = malloc(sizeof(char) * (n + 1));
    for (int i = 0; src[i] && i < n; i++)
        out[i] = src[i];
    out[n] = 0;
    return out;
}

char *my_strdup_to(char const *src, char *to)
{
    char *out = NULL;
    int i = 0;

    if (!src)
        return NULL;
    out = malloc(sizeof(char) * my_strlen(src));
    if (!out)
        return NULL;
    for (; src[i] && my_strncmp(&src[i], to, my_strlen(to)); i++)
        out[i] = src[i];
    out[i] = src[i];
    out[i + 1] = 0;
    return out;
}
