/*
** EPITECH PROJECT, 2024
** copy.c
** File description:
** libstring copy function
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

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    for (; this->str[pos] && i < n; i++) {
        s[i] = this->str[pos];
        pos++;
    }
    if (i < n) {
        s[i] = 0;
        i++;
    }
    return i;
}
