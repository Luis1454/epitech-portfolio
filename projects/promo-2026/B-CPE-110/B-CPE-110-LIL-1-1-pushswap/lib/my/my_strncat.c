/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task02
*/

#include <string.h>

int my_strlen(char const *str);

char *my_strncat(char *dest , char const *src , int nb)
{
    int j = my_strlen(dest);

    for (int i = 0; i < nb && src[i] != '\0'; i++)
        dest[j + i] = src[i];
    return dest;
}
