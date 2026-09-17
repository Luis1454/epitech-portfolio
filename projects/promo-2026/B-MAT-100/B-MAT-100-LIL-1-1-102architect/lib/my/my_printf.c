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
void place_value2(const char *str, va_list lst, int i);
void place_value3(const char *str, va_list lst, int i);
void my_put_sci(int nb, int state);
int get_base(int num, int base);
void print_pointer(unsigned long long n);

void place_value(const char *str, va_list lst, int i)
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
            place_value2(str, lst, i);
    }
}

void place_value2(const char *str, va_list lst, int i)
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
            place_value3(str, lst, i);
    }
}

void place_value3(const char *str, va_list lst, int i)
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

void my_printf(const char *str, ...)
{
    va_list lst;

    va_start(lst, str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else {
            place_value(str, lst, i);
            i++;
        }
    }

    va_end(lst);
}
