/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int i = 1;

    while (i <= nb) {
        if (nb % i && nb != i && i != 1)
            return 0;
        i++;
    }
    return 1;
}
