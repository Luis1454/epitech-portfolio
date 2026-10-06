/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** search a string
*/

#include "../../include/my.h"

static int is_found(char *str, char const *to_find, int n)
{
    for (int i = 0; to_find[i] && str[n + i]; i++)
        if (str[i + n] != to_find[i])
            return 0;
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i]; i++)
        if (is_found(str, to_find, i))
            return &str[i];
    return str;
}
