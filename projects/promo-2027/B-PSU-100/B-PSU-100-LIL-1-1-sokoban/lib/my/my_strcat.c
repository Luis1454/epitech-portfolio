/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

#include "../../include/my.h"

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    char *tmp = my_strdup(dest);
    int i = 0;

    if (dest != NULL)
        free(dest);
    dest = malloc(sizeof(char) * (len + my_strlen(src) + 1));
    for (; i < len; i++)
        dest[i] = tmp[i];
    free(tmp);
    for (i = 0; i < src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}
