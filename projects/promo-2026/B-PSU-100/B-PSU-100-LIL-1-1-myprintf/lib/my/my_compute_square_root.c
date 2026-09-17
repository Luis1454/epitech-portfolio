/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int compteur = 0;
    int result;

    while (result != nb) {
        compteur++;
        result = compteur * compteur;
        if (result > nb) {
            return 0;
        }
    }
    return compteur;
}
