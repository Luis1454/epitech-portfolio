/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** display a number
*/

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(long nb, long max);

static long get_unit(long n, long u)
{
    if (!u)
        return n;
    if (n < u / 10)
        return 0;
    n = n - n / u * u;
    for (; n > 9; n /= 10);
    return n;
}

static int sub_put_nbr(long nb, long size, long max)
{
    if (nb >= max) {
        my_put_nbr(max, __INT_MAX__);
        return 0;
    }
    for (; size < nb; size *= 10);
    if (nb / size == 1)
        size *= 10;
    for (; nb * 10 > 9 && size; nb -= get_unit(nb, size * 10) * size) {
        my_putchar(get_unit(nb, size) + '0');
        size /= 10;
    }
    for (; size > 1; size /= 10)
        my_putchar('0');
    return 0;
}

int get_int_len(long value)
{
    int i = 0;

    for (; value >= 1; value /= 10, i++);
    return i;
}

int my_put_nbr(long nb, long max)
{
    nb %= (long)((long)__INT_MAX__ + 1) * 2;
    int out = get_int_len(nb);
    long size = 1;

    if (!nb) {
        my_putstr("0");
        return 0;
    }
    if (nb <= -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    sub_put_nbr(nb, size, max);
    return out;
}
