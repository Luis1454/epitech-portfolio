/*
** EPITECH PROJECT, 2022
** my_put_nbr_to.c
** File description:
** display a number
*/

#include <unistd.h>

int get_int_len(long value);

int my_put_nbr_to_fd(long nb, long max, int fd);

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

static int sub_put_nbr_to_fd(long nb, long size, long max, int fd)
{
    if (nb >= max) {
        my_put_nbr_to_fd(max, __INT_MAX__, fd);
        return 0;
    }
    for (; size < nb; size *= 10);
    if (nb / size == 1)
        size *= 10;
    for (char c; nb * 10 > 9 && size; nb -= get_unit(nb, size * 10) * size) {
        c = (get_unit(nb, size) + '0');
        write(fd, &c, 1);
        size /= 10;
    }
    for (; size > 1; size /= 10)
        write(fd, "0", 1);
    return 0;
}

int my_put_nbr_to_fd(long nb, long max, int fd)
{
    nb %= (long)((long)__INT_MAX__ + 1) * 2;
    int out = get_int_len(nb);
    long size = 1;

    if (!nb) {
        write(fd, "0", 1);
        return 0;
    }
    if (nb <= -2147483648) {
        write(fd, "-2147483648", 11);
        return 0;
    }
    if (nb < 0) {
        nb *= -1;
        write(fd, "-", 1);
    }
    sub_put_nbr_to_fd(nb, size, max, fd);
    return out;
}
