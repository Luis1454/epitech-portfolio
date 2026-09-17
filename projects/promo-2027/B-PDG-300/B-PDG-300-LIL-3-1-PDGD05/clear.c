/*
** EPITECH PROJECT, 2024
** clear.c
** File description:
** libstring clear function
*/

#include <stdlib.h>
#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    if (this->str != NULL) {
        free(this->str);
    }
    this->str = malloc(sizeof(char));
    this->str[0] = 0;
}
