/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** task01
*/

#include "../../includes/my.h"

char *my_strcat(char *dest , char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    for (int i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    return dest;
}
