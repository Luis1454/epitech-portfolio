/*
** EPITECH PROJECT, 2024
** length.c
** File description:
** libstring length function
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

int length(const string_t *this)
{
    if (this == NULL)
        return -1;
    if (this->str == NULL)
        return -1;
    return my_strlen(this->str);
}
