/*
** EPITECH PROJECT, 2022
** task 05
** File description:
** C pool day 06
*/

#include "../../include/my.h"

char *my_strstr (char *str, char const *to_find)
{
    while (*str != '\0') {
        if (my_strncmp(str, to_find, my_strlen(to_find)) == 0)
            return str;
        str++;
    }
    return NULL;
}
