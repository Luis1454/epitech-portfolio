/*
** EPITECH PROJECT, 2021
** features.c
** File description:
** my own print function
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/my.h"

void print_unhandled(const char *str);

int get_base(int num, int base);

void my_put_sci(int nb, int state);

void place_value_end(const char *str, va_list lst, int i)
{
    switch (str[i + 1]) {
        case 'X':
            my_putstr(get_hex(va_arg(lst, int), 1));
            break;
        case 'p':
            print_pointer(va_arg(lst, int));
            break;
        case '%':
            my_putchar('%');
            break;
    }
}

void place_value_middle(const char *str, va_list lst, int i)
{
    switch (str[i + 1]) {
        case 'e':
            my_put_sci(my_getnbr(va_arg(lst, char *)), 0);
            break;
        case 'E':
            my_put_sci(my_getnbr(va_arg(lst, char *)), 1);
            break;
        case 'o':
            my_put_nbr(get_base(va_arg(lst, int), 8));
            break;
        case 'b':
            my_put_nbr(get_base(va_arg(lst, int), 2));
            break;
        case 'x':
            my_putstr(get_hex(va_arg(lst, int), 0));
            break;
        default:
            place_value_end(str, lst, i);
    }
}

void place_value_start(const char *str, va_list lst, int i)
{
    switch (str[i + 1]) {
        case 'i':
            my_put_nbr(va_arg(lst, int));
            break;
        case 'c':
            my_putchar(va_arg(lst, int));
            break;
        case 's':
            my_putstr(va_arg(lst, char *));
            break;
        case 'S':
            print_unhandled(va_arg(lst, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(lst, int));
            break;
        default:
            place_value_middle(str, lst, i);
    }
}

int my_printf(const char *str, ...)
{
    va_list lst;

    va_start(lst, str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else {
            place_value_start(str, lst, i);
            i++;
        }
    }
    va_end(lst);
    return 0;
}
