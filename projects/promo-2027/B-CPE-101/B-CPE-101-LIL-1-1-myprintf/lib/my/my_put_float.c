/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** display a float
*/

#include "../../include/my.h"


long double floor_float(long double nb, int n)
{
    int len = my_compute_power_it(10, n);

    return (long double)((int)(nb * len)) / len;
}

long double round_float(long double nb, int n)
{
    int tmp = (int)(my_compute_power_it(10, n + 1) * (nb - (int)nb)) % 10;
    long double out = tmp >= 5 ? nb + 1.0 / my_compute_power_it(10, n) : nb;

    return floor_float(out, n);
}

int get_end(double nb)
{
    int out = 0;

    nb -= (int)nb;
    nb *= 10;
    for (int i = 0; i < 6; i++) {
        if ((int)nb)
            out = i;
        nb -= (int)nb;
        nb *= 10;
    }
    return out;
}

int my_put_float(double nb, int quote, int fill, int round)
{
    if (!fill)
        quote = get_end(nb);
    quote = quote < 6 ? quote : 6;
    my_putstr(nb >= 0 ? "" : "-");
    nb *= nb >= 0 ? 1 : -1;
    my_put_nbr(nb + (!quote && floor_float(nb,
    quote) - (int)nb <= 0.5), __LONG_MAX__);
    if ((int)nb != floor_float(nb, quote) || quote)
        my_putchar('.');
    if (round)
        nb += (0.5 / my_compute_power_it(10, quote));
    for (; quote; nb *= 10, quote--) {
        nb -= (int)nb;
        my_putchar((int)(nb * 10) + '0');
    }
    return 1;
}
