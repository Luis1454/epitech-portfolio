/*
** EPITECH PROJECT, 2021
** show_number.c
** File description:
** display a number
*/

#include <unistd.h>

int get_nb_len(int nb);

int show_number(int nb)
{
    int len = get_nb_len(nb) + 1;
    int i = 0;
    int crop;
    int n = 0;
    char str[len];

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
        len = get_nb_len(nb) + 1;
    }
    while (nb) {
        crop = nb - (nb / 10) * 10;
        nb /= 10;
        str[len - i + n - 1] = crop + 48;
        i++;
    }
    write(1, &str, len);
    write(1, "\n", 1);
    return 0;
}
