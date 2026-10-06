/*
** EPITECH PROJECT, 2022
** my_putfoat
** File description:
** dsk
*/

#include "libmy.h"

void my_putfloat(double n, int prec)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    int part_int = n;
    int part_dec = 0;
    int i = 0;
    my_putnbr(part_int);
    my_putchar('.');
    n = n - part_int + 0.5 / my_pow(10, prec);
    while (i < prec) {
        n = n * 10;
        part_dec = n;
        my_putnbr(part_dec);
        n = n - part_dec;
        i++;
    }
}
