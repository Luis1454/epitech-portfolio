/*
** EPITECH PROJECT, 2024
** at.c
** File description:
** libstring append function
*/

#include <stdlib.h>
#include "string.h"

static int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++);
    return i;
}

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL)
        return -1;
    if (pos > my_strlen(this->str) || pos < 0)
        return -1;
    return this->str[pos];
}
