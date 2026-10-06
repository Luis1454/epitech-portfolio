/*
** EPITECH PROJECT, 2022
** flag_part2
** File description:
** dsk
*/

#include "libmy.h"

int flag_o (va_list ap)
{
    my_putnbr(my_octal_converter(va_arg(ap, int)));
    return 0;
}

int flag_pourcent (va_list ap)
{
    ap = ap;
    my_putchar('%');
    return 0;
}

int flag_x (va_list ap)
{
    my_putstr(my_hexadecimal_converter(va_arg(ap, int), 0));
    return 0;
}

int flag_xx (va_list ap)
{
    my_putstr(my_hexadecimal_converter(va_arg(ap, int), 1));
    return 0;
}

int flag_f (va_list ap)
{
    my_putfloat(va_arg(ap, double), 6);
    return 0;
}
