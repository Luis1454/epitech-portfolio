/*
** EPITECH PROJECT, 2024
** c_str.c
** File description:
** libstring c_str function
*/

#include <stdlib.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    return this ? this->str : NULL;
}
