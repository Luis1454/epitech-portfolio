/*
** EPITECH PROJECT, 2022
** my_getfloat.c
** File description:
** str to float
*/

#include "../../include/my.h"

double my_getfloat(const char *str)
{
    int sign = 1;
    double out = my_getnbr(str);
    int i = 0;

    for (; str[i] && !my_char_isnum(str[i]); i++)
        sign *= str[i] == '-' ? -1 : 1;
    for (; my_char_isnum(str[i]); i++);
    if (str[i] != '.')
        return out;
    i++;
    for (int n = 0; my_char_isnum(str[i + n]); n++)
        out += ((double)(str[i + n] - '0')) /
        my_compute_power_rec(10, n + 1) * sign;
    return out;
}
