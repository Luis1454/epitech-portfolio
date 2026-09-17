/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec.c
** File description:
** return a factorial in recursive
*/

long long my_normalize(long long nb);

int my_compute_factorial_rec(int nb)
{
    if (nb <= 0)
        return 0 + !nb;
    if (my_normalize(nb) > 12)
        return 0;
    if (my_normalize(nb) == 1)
        return nb;

    return nb * my_compute_factorial_rec(my_normalize(nb) - 1);
}
