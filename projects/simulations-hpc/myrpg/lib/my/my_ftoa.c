/*
** EPITECH PROJECT, 2022
** my_ftoa.c
** File description:
** float to string
*/

#include <stdlib.h>

static char *sub_my_ftoa(char *str, int i, int n, float f)
{
    int p = 1;

    while (n / p >= 10)
        p *= 10;
    while (p > 0) {
        str[i++] = '0' + n / p;
        n %= p;
        p /= 10;
    }
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
    int n = 0;

    if (f < 0) {
        str[i++] = '-';
        f = -f;
    }
    n = f;
    return sub_my_ftoa(str, i, n, f);
}
