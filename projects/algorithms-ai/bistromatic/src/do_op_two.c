/*
** EPITECH PROJECT, 2021
** do_op_two.c
** File description:
** Second file gor the do_op
*/

#include "../include/my.h"
#include "../include/main.h"

int adder(int k, int f)
{
    int r = 0;

    r = k + f;
    return (r);
}

int minner(int k, int f)
{
    int r = 0;

    r = k - f;
    return (r);
}

int multper(int k, int f)
{
    int r = 0;

    r = k * f;
    return (r);
}

int divver(int k, int f)
{
    int r = 0;

    r = k / f;
    return (r);
}

int modder(int k, int f)
{
    int r = 0;

    r = k % f;
    return (r);
}
