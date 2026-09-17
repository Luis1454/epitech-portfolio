/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** simplified printf function
*/

#include <stdarg.h>

int my_putchar(char c);

int my_putstr(char *str);

int my_strlen(const char *str);

int my_put_nbr(int nb);

int my_char_isalpha(char c);

int display_value(char type, va_list ap)
{
    switch (type) {
        case 'c':
            return my_putchar(va_arg(ap, int));
        case 's':
            return my_putstr(va_arg(ap, char *));
        case 'd':
            type = 'i';
        case 'i':
            return my_put_nbr(va_arg(ap, int));
        case '%':
            return my_putchar('%');
        default:
            return my_putchar('%');
    }
    return 0;
}

static int contain(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int mini_printf(const char *format, ...)
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
