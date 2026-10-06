/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-minishell1-mathis.zucchero
** File description:
** my_str_concat.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strconcat(char *dest, char const *src)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int j = 0;

    for (int i = 0; dest[i]; ++i, ++j)
        tmp[j] = dest[i];
    for (int i = 0; src[i]; ++i, ++j)
        tmp[j] = src[i];
    tmp[j] = '\0';
    return (tmp);
}
