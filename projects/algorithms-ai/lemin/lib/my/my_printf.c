/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** dsk
*/

#include "libmy.h"

int my_flag(char c, va_list ap)
{
    int(*flag[])(va_list) = {&flag_i, &flag_d, &flag_s, &flag_c, &flag_u,
    &flag_o, &flag_pourcent, &flag_x, &flag_xx, &flag_f, &flag_e, &flag_ee,
    &flag_p, &flag_b};
    char *flags = "idscuo%xXfeEpb";

    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == c)
            flag[i](ap);
    }
    return 0;
}

int flag(const char *typ_flag, int i, va_list ap)
{
    if (typ_flag[i] == '.') {
        i++;
        if (typ_flag[i + 1] == 'f')
            my_putfloat(va_arg(ap, double), typ_flag[i] - '0');
        i++;
    } else {
        my_flag (typ_flag[i], ap);
    }
    return i;
}

int my_printf(const char *typ_flag , ...)
{
    va_list ap;
    va_start(ap, typ_flag);
    for (int i = 0; typ_flag[i] != '\0'; i++) {
        if (typ_flag[i] == '%') {
            i++;
            i = flag(typ_flag, i, ap);
        } else {
            my_putchar(typ_flag[i]);
        }
    }
    va_end(ap);
    return 0;
}
