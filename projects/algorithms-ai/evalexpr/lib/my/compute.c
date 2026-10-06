/*
** EPITECH PROJECT, 2021
** compute.c
** File description:
** compute
*/

int add(int nb1, int nb2)
{
    int res = 0;

    res = nb1 + nb2;
    return res;
}

int sub(int nb1, int nb2)
{
    int res = 0;

    res = nb1 - nb2;
    return res;
}

int mult(int nb1, int nb2)
{
    int res = 0;

    res = nb1 * nb2;
    return res;
}

int div(int nb1, int nb2)
{
    int res = 0;

    if (nb2 != 0) {
        res = nb1 / nb2;
        return res;
    }
    return 0;
}

int mod(int nb1, int nb2)
{
    int res = 0;

    res = nb1 % nb2;
    return res;
}
