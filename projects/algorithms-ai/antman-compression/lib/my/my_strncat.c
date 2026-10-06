/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; i < src[i] && i < nb; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}

char *my_strncat_at(char *dest, char *src, int nb, int at)
{
    int i = 0;

    for (; i < src[i] && i < nb; i++)
        if (at + i >= 0)
            dest[at + i] = src[i];
    dest[at + i * at + i >= 0] = 0;
    free(src);
    return dest;
}
