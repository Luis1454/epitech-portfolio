/*
** EPITECH PROJECT, 2024
** init.c
** File description:
** libstring init functions
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

static void sub_init(string_t *this)
{
    this->copy = (void *)&copy;
    this->c_str = (void *)&c_str;
    this->empty = (void *)&empty;
    this->find_s = (void *)&find_s;
    this->find_c = (void *)&find_c;
    this->insert_c = (void *)&insert_c;
    this->insert_s = (void *)&insert_s;
    this->to_int = (void *)&to_int;
    this->split_s = (void *)&split_s;
    this->split_c = (void *)&split_c;
    this->print = (void *)&print;
}

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    this->str = s ? strdup(s) : NULL;
    this->append_c = (void *)&append_c;
    this->append_s = (void *)&append_s;
    this->length = (void *)&length;
    this->assign_c = (void *)&assign_c;
    this->assign_s = (void *)&assign_s;
    this->at = (void *)&at;
    this->clear = (void *)&clear;
    this->compare_s = (void *)&compare_s;
    this->compare_c = (void *)&compare_c;
    sub_init(this);
}
