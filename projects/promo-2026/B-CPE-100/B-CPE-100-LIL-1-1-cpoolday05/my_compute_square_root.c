/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int c;

    while (c != nb) {
        c++;
        if (c > nb)
            return 0;
        else if (c*c == nb)
            return c;
    }
}