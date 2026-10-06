/*
** EPITECH PROJECT, 2022
** my_arc_functions
** File description:
** arctan and arccos functions
*/

#include "../../include/my.h"
#include "../../include/my_macro_abs.h"

double my_atan(double nb)
{
    double a = 1.0 / my_sqrt(1.0 + nb * nb, 16);
    double b = 1;

    for (int i = 0; i < 11; i++) {
        a = (a + b) / 2;
        b = my_sqrt(a * b, 16);
    }
    return nb / (my_sqrt(1 + nb * nb, 16) * a);
}

double my_acos(double nb)
{
    if (ABS(nb) == 1)
        return (1 - nb) * PI / 2;
    return my_atan(-nb / my_sqrt(1 - nb * nb, 16)) + 2 * my_atan(1);
}
