/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** dsk
*/

#include "libmy.h"

char *my_strstr(char *str, char *to_find)
{
    while (*str != '\0') {
        if ((*str == *to_find) && my_strcmp(str, to_find)) {
            return (str);
        }
        str++;
    }
    return (0);
}
