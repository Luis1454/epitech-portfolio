/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** libstring print function
*/

#include <stdlib.h>
#include "string.h"

void print(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    write(1, this->str, strlen(this->str));
}
