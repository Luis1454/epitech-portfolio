/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** simplified printf function
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/my_macro_abs.h"

int display_arg(char c, char val, va_list ap, triplet data)
{
    char s_true[] = "TRUE";
    char s_false[] = "FALSE";

    if (val == c)
        switch (data.a) {
            case 0: return my_putchar(va_arg(ap, int));
            case 1: return my_putstr(data.b ? my_strlowcase(va_arg(ap, int)
                ? s_true : s_false, data.c) : va_arg(ap, char *));
            case 2: return my_put_nbr(c == 'u' ? ((long)__INT_MAX__ * 2 + 2 +
                va_arg(ap, int)) : va_arg(ap, int), __LONG_MAX__);
            case 3: return my_put_float(va_arg(ap, double), data.b, 1, 1);
            case 4: return my_put_base(va_arg(ap, unsigned long), data.b, c);
            case 5: return (c == 'g' || c == 'G') ? calcul(va_arg(ap,
            double), c) : ((c == 'e' || c == 'E') ? my_put_sci(va_arg(ap,
            double), c) : my_put_unhandled(va_arg(ap, char *)));
        }
    return 0;
}

int display_value(char val, va_list ap, int size, int p)
{
    size += display_arg('c', val, ap, (triplet){0, 0, 0});
    size += display_arg('s', val, ap, (triplet){1, 0, 0});
    size += display_arg('i', val, ap, (triplet){2, 0, 0});
    size += display_arg('d', val, ap, (triplet){2, 0, 0});
    size += display_arg('f', val, ap, (triplet){3, p, 0});
    size += display_arg('o', val, ap, (triplet){4, 8, 0});
    size += display_arg('p', val, ap, (triplet){4, 16, 0});
    size += display_arg('x', val, ap, (triplet){4, 16, 0});
    size += display_arg('X', val, ap, (triplet){4, 16, 0});
    size += display_arg('b', val, ap, (triplet){1, 1, 0});
    size += display_arg('B', val, ap, (triplet){1, 1, 1});
    size += display_arg('S', val, ap, (triplet){5, 0, 0});
    size += display_arg('u', val, ap, (triplet){2, 0, 0});
    size += display_arg('g', val, ap, (triplet){5, 0, 0});
    size += display_arg('G', val, ap, (triplet){5, 0, 0});
    size += display_arg('e', val, ap, (triplet){5, 0, 0});
    size += display_arg('E', val, ap, (triplet){5, 0, 0});
    return size ? size : val == '%' ? my_putchar('%') : 0;
}

int get_precision_modif(const char *format, int *i)
{
    int nb = 0;
    for (; format[*i + 1] && !my_char_isalpha(format[*i + 1])
    && format[*i + 1] != '.' && format[*i + 1] != '%'; (*i)++);
    if (format[*i + 1] == '.') {
        nb = my_getnbr(&format[*i + 2]);
        for ((*i)++; format[*i + 1] && my_char_isnum(format[*i + 1]); (*i)++);
    } else
        return 6;
    return nb;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int len = 0;
    int precision = 6;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            len++;
        }
        if (format[i] == '%' && i + 1 < my_strlen(format)) {
            precision = get_precision_modif(format, &i);
            len += display_value(format[i + 1], ap, 0, precision);
            i++;
        }
    }
    va_end(ap);
    return len;
}
