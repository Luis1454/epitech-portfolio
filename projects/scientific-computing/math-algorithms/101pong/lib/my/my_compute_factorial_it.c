/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it.c
** File description:
** return a factorial in iterative
*/

long long my_normalize(long long nb);

int my_compute_factorial_it(int nb)
{
    long long out = 1;

    for (int i = my_normalize((long long) nb); i; out *= i, i--)
        if (my_normalize(out) > __INT_MAX__)
            return 0;
    return ((nb > 0) * (int) out) + !nb;
}
