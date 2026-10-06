/*
** EPITECH PROJECT, 2022
** sub_my_printf.c
** File description:
** sub printf file
*/

#include "../../include/my.h"

int get_precision(int nb)
{
    int i = 0;

    for (; nb; nb /= 10, i++);
    return i;
}

int calcul(double nb, char c)
{
    int n = 0;
    int tmp = nb;
    int len;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (1 <= nb && nb < 1000000)
        my_put_float(nb, 10, 0, 1);
    else {
        for (; nb >= 10; nb /= 10, n++);
        for (; nb < 1; nb *= 10, n--);
        len = my_printf("%f%c", nb, c - 2);
        len += my_putstr(tmp > 0 ? "+" : "");
        return len + my_printf("%d", n);
    }
    return 0;
}

int my_put_sci(double nb, char c)
{
    int n = 0;
    int len;
    int tmp = nb;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    for (; nb >= 10; nb /= 10, n++);
    for (; nb < 1; nb *= 10, n--);
    len = my_printf("%f%c", nb, c);
    len += my_putstr(tmp > 0 ? "+" : "");
    return len + my_printf("%d", n);
}
