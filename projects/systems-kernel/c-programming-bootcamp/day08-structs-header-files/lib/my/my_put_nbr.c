/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** display a number
*/

void my_putchar(char c);

int get_unit(int n, int u);

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}

int sub_put_nbr(int nb, int size)
{
    if (nb >= 2147483647) {
        my_putstr("2147483647");
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

int my_put_nbr(int nb)
{
    int size = 1;

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
    sub_put_nbr(nb, size);
    return 0;
}
