/*
** EPITECH PROJECT, 2024
** empty.c
** File description:
** libstring empty function
*/

#include <stdlib.h>
#include "string.h"

int empty(const string_t *this)
{
    return !this || !this->str || !*this->str;
}
