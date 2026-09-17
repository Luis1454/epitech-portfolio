/*
** EPITECH PROJECT, 2022
** rush.c
** File description:
** rush file
*/

#include "include/my.h"
#include "include/my_macro_abs.h"

int compute_sum(int *tab)
{
    int out = 0;

    for (int i = 0; i < 26; i++)
        out += tab[i];
    return out;
}

int display_count(int *tab, char c)
{
    int sum = compute_sum(tab);
    int count = tab[my_charlowcase(c) - 'a'];
    int ratio = (count * 10000 / sum);

    my_putchar(c);
    my_putchar(':');
    my_put_nbr(tab[my_charlowcase(c) - 'a']);
    my_putstr(" (");
    my_put_nbr(ratio / 100);
    my_putchar('.');
    ratio % 100 ? my_put_nbr(ratio % 100) : my_putstr("00");
    my_putstr("\045)\n");
    return 0;
}

int predict_language(int *tab)
{
    double ratio = (tab[0] * 10000 / compute_sum(tab)) / 100;

    if (ratio >= 10) {
        my_putstr("=> Spanish\n");
        return 0;
    }
    ratio = (tab['o' - 'a'] * 10000 / compute_sum(tab)) / 100;
    if (7 <= ratio && ratio <= 8) {
        my_putstr("=> English\n");
        return 0;
    }
    ratio = (tab['n' - 'a'] * 10000 / compute_sum(tab)) / 100;
    if (8.5 <= ratio)
        my_putstr("=> German\n");
    else
        my_putstr("=> French\n");
    return 0;
}

int rush(int ac, char const **av)
{
    int tab[26] = {0};

    if (ac < 2) {
        write(2, "Not enougth arguments !\n", 24);
        return 84;
    }
    for (int i = 0; av[1][i]; i++)
        if (my_char_isalpha(av[1][i]))
            tab[my_charlowcase(av[1][i]) - 'a']++;
    for (int i = 2; i < ac; i++)
        if (my_strlen(av[i]) > 1 || !my_char_isalpha(*av[i])) {
            write(2, "Invalid syntax !\n", 17);
            return 84;
        }
    for (int i = 2; i < ac; i++)
        display_count(tab, *av[i]);
    predict_language(tab);
    return 0;
}
