/*
** EPITECH PROJECT, 2021
** recursive_power.c
** File description:
** return power using a recursive
*/

int recursive_power(int nb, int p)
{
    int out;

    if (!p)
        return 1;
    else if (p < 0)
        return 0;

    out = nb * recursive_power(nb, p - 1);
    return out;
}
