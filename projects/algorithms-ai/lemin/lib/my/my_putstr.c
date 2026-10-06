/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** dsk
*/

#include "libmy.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
