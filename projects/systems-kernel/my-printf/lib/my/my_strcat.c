/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    if (!dest)
        dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; i < src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}
