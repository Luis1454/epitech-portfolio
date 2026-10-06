/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** compute the power of a number
*/

long long my_normalize(long long nb)
{
    return nb < 0 ? -nb : nb;
}

long long my_compute_power_it(int nb, int p)
{
    long long out = 1;

    if (p <= 0)
        return 0 + !p;
    for (int i = 0; i < p; i++, out *= nb);
    return out;
}
