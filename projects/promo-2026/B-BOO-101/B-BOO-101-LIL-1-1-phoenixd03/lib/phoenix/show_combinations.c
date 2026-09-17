/*
** EPITECH PROJECT, 2021
** show_combinations.c
** File description:
** print formated numbers
*/

#include <unistd.h>

int my_strlen(char *str);

int get_nb_len(int nb);

int print_nbr(int nbr, int p)
{
    int len = get_nb_len(nbr);
    int i = 0;
    int crop;
    int tmp = 10;
    char str[len];

    while (nbr) {
        crop = nbr - (nbr / 10) * 10;
        if (crop >= tmp || !crop)
            return 0;
        tmp = crop;
        nbr /= 10;
        str[len - i] = crop + 48;
        i++;
    }
    if (p)
        write(0, &str, len + 1);
    return 1;
}

int pwr(int nb)
{
    int n = 1;

    for (int i = 0; i < nb; i++)
        n *= 10;
    return n;
}

int show_combinations(void)
{
    int val = 1000;
    int cnt = val / 100;
    int v = 0;

    while (cnt <= pwr(get_nb_len(val))) {
        if (print_nbr(cnt, 0)) {
            if (v)
                write(1, ", ", 2);
            for (int i = 0; i < get_nb_len(val) - get_nb_len(cnt) - 1; i++)
                write(1, "0", 1);
            if (!cnt)
                write(1, "0", 1);
            else
                print_nbr(cnt, 1);
            v = 1;
        }
        cnt++;
    }
    write(1, "\n", 1);
    return 0;
}