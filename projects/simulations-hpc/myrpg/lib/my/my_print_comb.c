/*
** EPITECH PROJECT, 2022
** my_print_comb.c
** File description:
** print all ascending numbers
*/

void my_putchar(char c);

int get_unit(int n, int u)
{
    if (!u)
        return n;
    if (n < u / 10)
        return 0;
    n = n - n / u * u;
    for (; n > 9; n /= 10);
    return n;
}

int my_print_comb(void)
{
    for (int i = 0; i < 1000; i++) {
        if (get_unit(i, 10) > get_unit(i, 100)
        && get_unit(i, 100) > get_unit(i, 1000)) {
            my_putchar(get_unit(i, 1000) + '0');
            my_putchar(get_unit(i, 100) + '0');
            my_putchar(get_unit(i, 10) + '0');
            i != 789 ? my_putchar(',') : 0;
            i != 789 ? my_putchar(' ') : 0;
        }
    }
    my_putchar('\n');
    return 0;
}
