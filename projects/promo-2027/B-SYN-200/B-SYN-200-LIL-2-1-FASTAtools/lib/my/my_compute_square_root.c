/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** return the square root of a number
*/

int my_compute_power_it(int nb, int p);

int my_compute_square_root(int nb)
{
    for (int i = 1; i <= nb; i++)
        if (my_compute_power_it(i, 2) == nb)
            return i;
    return 0;
}
