/*
** EPITECH PROJECT, 2022
** my_print_comb.c
** File description:
** print all ascending numbers
*/

void my_putchar(char c);

int my_putstr(char *str);

int get_unit(int n, int u);

int display_nbr(int lvl, int nb)
{
    int i = 1;

    for (int j = 1; j < lvl; j++, i *= 10);
    for (; i; i /= 10)
        my_putchar(get_unit(nb, i * 10) + '0');
    return 0;
}

int is_displayable(int nb, int lvl)
{
    int i = 1;
    for (int j = 1; j < lvl; j++, i *= 10) {
        if (get_unit(nb, i * 10) <= get_unit(nb, i * 100) || lvl > 10)
            return 0;
    }
    return 1;
}

int is_last(int nb, int lvl)
{
    int i = 1;
    int max = 9;

    for (int j = 1; j < lvl + 1; j++, i *= 10, max--) {
        if (get_unit(nb, i * 10) != max)
            return 0;
    }
    return 1;
}

int my_print_combn(int n)
{
    int size = 1;

    for (int i = 0; i < n; size *= 10, i++);
    for (int i = 0; i < size; i++) {
        if (is_displayable(i, n)) {
            display_nbr(n, i);
            !is_last(i, n) ? my_putstr(", ") : 0;
        }
    }
    my_putchar('\n');
    return 0;
}
