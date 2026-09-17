/*
** EPITECH PROJECT, 2022
** my_ftoa.c
** File description:
** float to string
*/

#include <stdlib.h>

static int is_integer(float f)
{
    return (int)f == f;
}

static char *sub_my_ftoa(char *str, int i, float f)
{
    int p = 1;
    int n = f;

    for (; n / p >= 10; p *= 10);
    for (; p > 0; n %= p, p /= 10)
        str[i++] = '0' + n / p;
    if (is_integer(f))
        return str;
    str[i++] = '.';
    f -= (int)f;
    for (int j = 0; j < 2; j++) {
        f *= 10;
        str[i++] = '0' + (int)f;
        f -= (int)f;
    }
    str[i] = 0;
    return str;
}

char *my_ftoa(float f)
{
    char *str = malloc(sizeof(char) * 20);
    int i = 0;

    for (int j = 0; j < 20; j++)
        str[j] = 0;
    if (f < 0) {
        str[i++] = '-';
        f = -f;
    }
    return sub_my_ftoa(str, i, f);
}
