/*
** EPITECH PROJECT, 2024
** delete.c
** File description:
** libstring delete functions
*/

#include <stdlib.h>
#include "string.h"

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}
