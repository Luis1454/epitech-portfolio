/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** task07
*/

#include "./myprint.h"

static int  get_exception(int nb)
{
    if (!nb) {
        my_putchar('0');
        return 1;
    }
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return 1;
    }
    return 0;
}

void cut_number(int nb)
{
    char digit = '0';
    if (nb) {
        digit = (nb % 10) + '0';
        cut_number(nb / 10);
        my_putchar(digit);
    }
}

int my_put_nbr(int nb)
{
    if (get_exception(nb))
        return 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    cut_number(nb);
    return 0;
}
