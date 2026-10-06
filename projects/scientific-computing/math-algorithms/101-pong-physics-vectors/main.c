/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "include/my.h"
#include "include/my_macro_abs.h"

int display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    x0  ball abscissa at time t - 1\n");
    my_putstr("    y0  ball ordinate at time t - 1\n");
    my_putstr("    z0  ball altitude at time t - 1\n");
    my_putstr("    x1  ball abscissa at time t\n");
    my_putstr("    y1  ball ordinate at time t\n");
    my_putstr("    z1  ball altitude at time t\n");
    my_putstr("    n  time shift (greater than or equal to zero, integer)\n");
    return 0;
}

int sub_pong(double *vect_a, double *vect_b, double *deriv)
{
    double angle = 0;
    double rad = 0;
    double root = my_sqrt(deriv[0] * deriv[0] +
    deriv[1] * deriv[1] + deriv[2] * deriv[2], 16);

    if (!deriv[2])
        return 84;
    if (!vect_b[0] || -vect_b[2] / deriv[2] < 0)
        my_printf("The ball won't reach the paddle.\n");
    else {
        if (!root)
            return 84;
        rad = my_acos(deriv[2] / root);
        angle = 180 * (rad - PI / 2) / PI;
        angle = ABS(angle);
        my_printf("The incidence angle is:\n%f degrees\n", angle);
    }
    return 0;
}

int my_pong(const char *argv[])
{
    double vect_a[3] = {my_getfloat(argv[1]),
    my_getfloat(argv[2]), my_getfloat(argv[3])};
    double vect_b[3] = {my_getfloat(argv[4]),
    my_getfloat(argv[5]), my_getfloat(argv[6])};
    double deriv[3] = {vect_b[0] - vect_a[0],
    vect_b[1] - vect_a[1], vect_b[2] - vect_a[2]};
    double n = my_getfloat(argv[7]);

    if ((int)n != n || n < 0)
        return 84;
    my_printf("The velocity vector of the ball is:\n");
    my_printf("(%f, %f, %f)\n", deriv[0], deriv[1], deriv[2]);
    my_printf("At time t + %i, ball coordinates will be:\n", (int)n);
    my_printf("(%f, %f, %f)\n", vect_b[0] + deriv[0] * n,
    vect_b[1] + deriv[1] * n, vect_b[2] + deriv[2] * n);
    return sub_pong(vect_a, vect_b, deriv);
}

int handle_wrong_args(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isnum(str[i]) && str[i] != '-' && str[i] != '.')
            return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 8 && argc != 2)
        return 84;
    if (argc == 2)
        return display_usage();
    for (int i = 1; i < argc; i++)
        if (handle_wrong_args(argv[i]))
            return 84;
    return my_pong(argv);
}
