/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec.c
** File description:
** task02
*/

int my_compute_factorial_rec(int nb)
{
    int s = 1;

    if (nb == 0)
        return 1;
    else if (nb < 0 || nb > 12)
        return 0;

    nb--;
    s = my_compute_factorial_rec(nb) * (nb+1);

    return s;
}