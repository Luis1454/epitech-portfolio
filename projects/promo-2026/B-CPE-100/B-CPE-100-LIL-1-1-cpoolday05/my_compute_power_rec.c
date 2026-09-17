/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int s = 1;

    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;

    if (nb == 0)
        return 1;
    s = my_compute_power_rec(nb, p-1) * nb;

    return s;
}