/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../../includes/my.h"

char *my_strncpy(char *dest , char const *src , int n);

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *dest = malloc(len + 1);

    if (dest == NULL)
        return (NULL);
    dest = my_strcpy(dest, str);
    dest[len] = 0;
    return (dest);
}

char *my_strndup(char *str, int n)
{
    char *dest = malloc(n + 1);

    if (dest == NULL)
        return (NULL);
    dest = my_strncpy(dest, str, n);
    dest[n] = 0;
    return (dest);
}
