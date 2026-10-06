/*
** EPITECH PROJECT, 2024
** insert.c
** File description:
** libstring insert function
*/

#include <stdlib.h>
#include "string.h"

static void sub_insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp = NULL;
    int a = strlen(this->str);
    int b = strlen(str);

    tmp = strdup(this->str);
    if (this->str)
        free(this->str);
    this->str = malloc(sizeof(char) * (a + b + 1));
    if (this->str == NULL)
        return;
    for (int i = 0; i < pos; i++)
        this->str[i] = tmp[i];
    for (int i = pos; str[i - pos]; i++)
        this->str[i] = str[i - pos];
    for (int i = pos + b; tmp[i - b]; i++)
        this->str[i] = tmp[i - b];
    this->str[a + b] = 0;
    free(tmp);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    if (this == NULL || str == NULL)
        return;
    if (0 > pos || pos > strlen(this->str))
        return;
    sub_insert_c(this, pos, str);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (!str || !str->str || !this->str)
        return;
    insert_c(this, pos, str->str);
}
