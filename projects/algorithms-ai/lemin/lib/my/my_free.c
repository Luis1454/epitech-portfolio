/*
** EPITECH PROJECT, 2023
** my_free
** File description:
** dsk
*/

#include "libmy.h"

void my_free(int count, ...)
{
    va_list args;
    va_start(args, count);
    void *p;
    ArgumentType type;

    for (int i = 0; i < count; i++) {
        p = va_arg(args, void *);
        type = va_arg(args, ArgumentType);
        if (type == STRING_ARRAY)
            my_free_array(p);
        if (type == STRING)
            free(p);
    }
    va_end(args);
}
