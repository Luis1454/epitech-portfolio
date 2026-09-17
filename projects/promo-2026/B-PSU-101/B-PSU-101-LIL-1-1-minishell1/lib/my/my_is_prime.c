/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int i;

    i = 1;
    if (nb < 1)
        return 0;
    while (i <= nb) {
        if ((nb % i) == 0 && nb != i && i > 1) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;

}
