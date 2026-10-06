/*
** EPITECH PROJECT, 2024
** assign.c
** File description:
** libstring assign functions
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

void assign_c(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = malloc(sizeof(char) * (my_strlen(s) + 1));
    if (this->str == NULL)
        return;
    for (int i = 0; s[i]; i++)
        this->str[i] = s[i];
    this->str[my_strlen(s)] = 0;
}

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = malloc(sizeof(char) * (my_strlen(str->str) + 1));
    if (this->str == NULL)
        return;
    for (int i = 0; str->str[i]; i++)
        this->str[i] = str->str[i];
    this->str[my_strlen(str->str)] = 0;
}
