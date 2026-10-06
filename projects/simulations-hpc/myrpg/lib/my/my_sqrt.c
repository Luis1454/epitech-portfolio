/*
** EPITECH PROJECT, 2022
** my_sqrt.c
** File description:
** find a square root
*/

#include "../../include/my.h"

double my_sqrt(double nb, int quote)
{
    double out = 0;
    double t;

    for (int i = 0; i <= quote; i++)
        for (t = 1.0 / my_compute_power_it(10, i); (out + t) * (out + t) <= nb;
        out += t);
    return out;
}
