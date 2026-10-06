/*
** EPITECH PROJECT, 2022
** my_getbase.c
** File description:
** base convertion
*/

#include "../../include/my.h"

unsigned long my_getbase(long nb, long base)
{
    unsigned long tmp = 1;
    unsigned long out = 0;

    if (base < 10) {
        for (; nb; nb /= base) {
            out += (nb % base) * tmp;
            tmp *= 10;
        }
        return out;
    } else
        return 0;
}

char *my_strbase(unsigned long nb, long base, int is_upper)
{
    char *out;
    long len = 1;
    unsigned long val = nb;
    long i;

    for (i = 0; nb > 0; nb /= base, len++);
    out = malloc(sizeof(char) * len);
    for (i = 0, nb = val; nb; i++) {
        val = nb % base;
        nb /= base;
        if (val < 10)
            out[i] = val + '0';
        else
            out[i] = val + (is_upper ? 'A' : 'a') - 10;
    }
    out[i] = 0;
    out = my_revstr(out);
    return out;
}

unsigned long my_put_base(unsigned long nb, long base, char c)
{
    char *out = my_strbase(nb, base, c == 'X');

    if ((c != 'p' || nb) && base == 16)
        my_putstr(c == 'X' ? "0X" : "0x");
    if (!nb) {
        my_putstr(c == 'p' ? "(nil)" : "0");
        return 0;
    }
    my_strupcase(out);
    my_strlowcase(out, c == 'X');
    my_putstr(out);
    free(out);
    return 0;
}
