/*
** EPITECH PROJECT, 2022
** flag_part3
** File description:
** dsk
*/

#include "libmy.h"

int flag_e (va_list ap)
{
    my_scientifique_converter(va_arg(ap, double), 0);
    return 0;
}

int flag_ee (va_list ap)
{
    my_scientifique_converter(va_arg(ap, double), 1);
    return 0;
}

int flag_p (va_list ap)
{
    my_putadress(va_arg(ap, long long *));
    return 0;
}

int flag_b (va_list ap)
{
    my_binary_converter(va_arg(ap, unsigned int));
    return 0;
}
