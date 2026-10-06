/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** task01
*/

#include <stdlib.h>
#include "../../includes/my.h"

char *my_strcat(char *dest , char const *src)
{
    int len = my_strlen(dest);
    int i;

    char *out = malloc(sizeof(char) * (len + my_strlen(src)));

    out = my_strcpy(out, dest);

    for (i = 0; src[i]; i++)
        out[len + i] = src[i];
    out[len + i] = 0;
    return out;
}
