/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** task03
*/

int my_compute_power_it(int nb , int p)
{
    int s = 1;
    int i;
    
    for (i = 0; i < p; i++) {
        s *= nb;
    }

    if (nb == 0)
        return 0;

    else if (p <= 0)
        return 1;

    return s;
}