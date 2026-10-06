/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** move and resize a string using malloc
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char * out = malloc(sizeof(char) * my_strlen(src));

    my_strcpy(out, src);
    return out;
    free(out);
}
