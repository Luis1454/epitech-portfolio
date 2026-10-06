/*
** EPITECH PROJECT, 2023
** my_put_nbr_err
** File description:
** print a number on the strerr output
*/

#include <unistd.h>

int get_int_len(long value);

int my_print_error(char const *str);

int my_put_nbr_err(long nb, long max);

long get_unit(long n, long u);

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

static int sub_put_nbr_err(long nb, long size, long max)
{
    if (nb >= max) {
        my_put_nbr_err(max, __INT_MAX__);
        return 0;
    }
    for (; size < nb; size *= 10);
    if (nb / size == 1)
        size *= 10;
    for (; nb * 10 > 9 && size; nb -= get_unit(nb, size * 10) * size) {
        my_putchar_err(get_unit(nb, size) + '0');
        size /= 10;
    }
    for (; size > 1; size /= 10)
        my_print_error("0");
    return 0;
}

int my_put_nbr_err(long nb, long max)
{
    nb %= (long)((long)__INT_MAX__ + 1) * 2;
    int out = get_int_len(nb);
    long size = 1;

    if (!nb) {
        my_print_error("0");
        return 0;
    }
    if (nb <= -2147483648) {
        my_print_error("-2147483648");
        return 0;
    }
    if (nb < 0) {
        nb *= -1;
        my_print_error("-");
    }
    sub_put_nbr_err(nb, size, max);
    return out;
}
