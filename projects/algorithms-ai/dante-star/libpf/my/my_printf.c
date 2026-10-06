/*
** EPITECH PROJECT, 2022
** disp_stdarg
** File description:
** disp_stdarg.c
*/

#include <stdarg.h>
#include "./myprint.h"

void strings(va_list *list)
{
    my_putstr(va_arg(*list, char *));
}

void integers(va_list *list)
{
    my_put_nbr(va_arg((*list), int));
}

void character(va_list *list)
{
    my_putchar(va_arg((*list), int));
}

int my_printf(char *s, ...)
{
    int j = 0;
    va_list list;
    va_start(list, s);
    void (*name[6])(va_list *list) = {&strings, &integers, &character,
                                    &integers, &my_alpha, &character};
    char arg[6][2] = {"%s", "%i", "%c", "%d", "%S", "%%"};

    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] != '%') {
            my_putchar(s[i]);
        } else if (cmp(s[i], s[i + 1],arg[j]) == 0) {
            name[j](&list);
            j = 0;
            i++;
        } else {
            j++;
            i--;
        }
    }
    va_end(list);
    return 0;
}
