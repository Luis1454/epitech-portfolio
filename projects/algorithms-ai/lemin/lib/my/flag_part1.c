/*
** EPITECH PROJECT, 2022
** flag_part1
** File description:
** dsk
*/

#include "libmy.h"

int flag_i (va_list ap)
{
    my_putnbr(va_arg(ap, int));
    return 0;
}

int flag_d (va_list ap)
{
    my_putnbr(va_arg(ap, int));
    return 0;
}

int flag_s (va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return 0;
}

int flag_c (va_list ap)
{
    my_putchar(va_arg(ap, int));
    return 0;
}

int flag_u (va_list ap)
{
    my_putnbr(va_arg(ap, unsigned int));
    return 0;
}
