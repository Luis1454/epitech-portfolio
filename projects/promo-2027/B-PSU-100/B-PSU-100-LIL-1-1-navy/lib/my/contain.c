/*
** EPITECH PROJECT, 2022
** contain.c
** File description:
** contain fonctions
*/

#include "../../include/my_macro_abs.h"
#include "../../include/my.h"

int contain(char c, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int only_contain(const char *valid, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!contain(str[i], valid))
            return 0;
    return 1;
}

int are_equals(const char *str_a, const char *str_b)
{
    for (int i = 0; i < MIN(my_strlen(str_a), my_strlen(str_a)); i++)
        if (str_a[i] != str_b[i])
            return 0;
    return 1;
}

int find_out(const char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return i;
    return -1;
}
