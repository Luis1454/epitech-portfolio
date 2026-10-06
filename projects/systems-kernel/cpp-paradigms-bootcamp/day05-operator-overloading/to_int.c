/*
** EPITECH PROJECT, 2024
** to_int.c
** File description:
** libstring to_int function
*/

#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return 0;
    return atoi(this->str);
}
