/*
** EPITECH PROJECT, 2023
** requirement.c
** File description:
** requirements
*/

int my_factrec_synthesis(int nb)
{
    if (nb <= 0 || nb > 12)
        return !nb;
    return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;

    if (nb < 0)
        return -1;
    for (; i * i < nb; i++);
    if (i * i == nb)
        return i;
    return -1;
}
