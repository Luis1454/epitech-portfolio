/*
** EPITECH PROJECT, 2024
** append.c
** File description:
** libstring append function
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

void append_s(string_t *this, const string_t *ap)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) *
        (my_strlen(this->str) + my_strlen(ap->str) + 1));

    if (this == NULL)
        return;
    if (this->str == NULL) {
        assign_s(this, ap);
        return;
    }
    for (; this->str[i]; i++)
        new_str[i] = this->str[i];
    for (; ap->str[j]; j++)
        new_str[i + j] = ap->str[j];
    new_str[i + j] = 0;
    free(this->str);
    this->str = new_str;
}

void append_c(string_t *this, const char *ap)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) *
        (my_strlen(this->str) + my_strlen(ap) + 1));

    if (this == NULL)
        return;
    if (this->str == NULL) {
        assign_c(this, ap);
        return;
    }
    for (; this->str[i]; i++)
        new_str[i] = this->str[i];
    for (; ap[j]; j++)
        new_str[i + j] = ap[j];
    new_str[i + j] = 0;
    free(this->str);
    this->str = new_str;
}
