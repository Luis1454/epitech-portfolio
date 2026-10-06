/*
** EPITECH PROJECT, 2024
** find.c
** File description:
** libstring find function
*/

#include <stdlib.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this == NULL || this->str == NULL || str == NULL || str->str == NULL)
        return -1;
    if (pos > strlen(this->str) || pos < 0)
        return -1;
    for (; this->str[pos]; pos++) {
        if (this->str[pos] == str->str[0])
            return pos;
    }
    return -1;
}

int find_c(const string_t *this, char const *str, size_t pos)
{
    if (this == NULL || this->str == NULL || str == NULL)
        return -1;
    if (pos > strlen(this->str) || pos < 0)
        return -1;
    for (; this->str[pos]; pos++) {
        if (this->str[pos] == str[0])
            return pos;
    }
    return -1;
}
