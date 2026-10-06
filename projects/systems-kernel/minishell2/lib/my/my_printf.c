/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** simplified printf function
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_macro_abs.h"

int display_arg(char c, char val, va_list ap, int *data)
{
    char s_true[] = "TRUE";
    char s_false[] = "FALSE";

    if (val == c)
        switch (data[0]) {
            case 0: my_putchar(va_arg(ap, int)); break;
            case 1: my_putstr(data[1] ? my_strlowcase(va_arg(ap, int)
                ? s_true : s_false, data[2]) : va_arg(ap, char *)); break;
            case 2:
                my_put_nbr(c == 'u' ? ((long)__INT_MAX__ * 2 + 2 +
                va_arg(ap, int)) : va_arg(ap, int), __LONG_MAX__); break;
            case 3: my_put_float(va_arg(ap, double), data[1], 1, 1); break;
            case 4: my_put_base(va_arg(ap, unsigned long), data[1], c); break;
            case 5: (c == 'g' || c == 'G') ? calcul(va_arg(ap,
            double), c) : ((c == 'e' || c == 'E') ? my_put_sci(va_arg(ap,
            double), c) : my_put_unhandled(va_arg(ap, char *))); break;
        }
    free(data);
    return 0;
}

int *wrap(int a, int b)
{
    int *w = malloc(sizeof(int) * 2);
    w[0] = a;
    w[1] = b;
    return w;
}

int *wrap_3(int a, int b, int c)
{
    int *w = malloc(sizeof(int) * 3);
    w[0] = a;
    w[1] = b;
    w[2] = c;
    return w;
}

int display_value(char val, va_list ap)
{
    display_arg('c', val, ap, wrap(0, 0));
    display_arg('s', val, ap, wrap(1, 0));
    display_arg('i', val, ap, wrap(2, 0));
    display_arg('d', val, ap, wrap(2, 0));
    display_arg('f', val, ap, wrap(3, 6));
    display_arg('o', val, ap, wrap(4, 8));
    display_arg('p', val, ap, wrap(4, 16));
    display_arg('x', val, ap, wrap(4, 16));
    display_arg('X', val, ap, wrap(4, 16));
    display_arg('b', val, ap, wrap_3(1, 1, 0));
    display_arg('B', val, ap, wrap_3(1, 1, 1));
    display_arg('S', val, ap, wrap(5, 0));
    display_arg('u', val, ap, wrap(2, 0));
    display_arg('g', val, ap, wrap(5, 0));
    display_arg('G', val, ap, wrap(5, 0));
    display_arg('e', val, ap, wrap(5, 0));
    display_arg('E', val, ap, wrap(5, 0));
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int len = 0;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            len++;
        }
        if (format[i] == '%' && i + 1 < my_strlen(format)) {
            len += display_value(format[i + 1], ap);
            i++;
        }
    }
    va_end(ap);
    return len;
}
