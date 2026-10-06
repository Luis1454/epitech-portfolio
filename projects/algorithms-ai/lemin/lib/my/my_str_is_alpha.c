/*
** EPITECH PROJECT, 2023
** my_str_is_alpha
** File description:
** dsk
*/

#include "libmy.h"

int my_str_is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
            return 0;
    }
    return 1;
}
