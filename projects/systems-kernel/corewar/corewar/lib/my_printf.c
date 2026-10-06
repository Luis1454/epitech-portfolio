/*
** EPITECH PROJECT, 2022
** PushSwap
** File description:
** my_printf.c
*/

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

void args(char c, va_list *ap)
{
    switch (c) {
        case 'c':
            my_putchar(va_arg(*ap, int));
            break;
        case 's':
            my_putstr(va_arg(*ap, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(*ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(*ap, int));
            break;
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
            args(format[i + 1], &ap);
            i++;
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
    return (0);
}
