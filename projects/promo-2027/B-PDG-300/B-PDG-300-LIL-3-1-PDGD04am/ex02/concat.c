/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main file
*/

#include <string.h>
#include <stdlib.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    int l1 = (int)strlen(str1);
    int l2 = (int)strlen(str2);

    if (*res)
        free(*res);
    *res = malloc(sizeof(const char) * (l1 + l2 + 1));
    for (int i = 0; str1[i]; i++)
        (*res)[i] = str1[i];
    for (int i = 0; str2[i]; i++)
        (*res)[i + l1] = str2[i];
    (*res)[l1 + l2] = 0;
}

void concat_struct(concat_t *str)
{
    int l1 = (int)strlen(str->str1);
    int l2 = (int)strlen(str->str2);

    if (str->res)
        free(str->res);
    str->res = malloc(sizeof(const char) * (l1 + l2 + 1));
    for (int i = 0; str->str1[i]; i++)
        str->res[i] = str->str1[i];
    for (int i = 0; str->str2[i]; i++)
        str->res[i + l1] = str->str2[i];
    str->res[l1 + l2] = 0;
}
