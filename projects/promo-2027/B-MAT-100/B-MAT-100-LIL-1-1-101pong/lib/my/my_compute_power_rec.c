/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** return a power in recursive
*/

int my_compute_power_rec(int nb, int p)
{
    if (p <= 0)
        return 0 + !p;
    if (p == 1)
        return nb;

    return nb * my_compute_power_rec(nb, p - 1);
}
