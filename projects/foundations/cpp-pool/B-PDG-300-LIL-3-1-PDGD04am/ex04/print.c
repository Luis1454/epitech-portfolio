/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** day 04
*/

#include <unistd.h>
#include "print.h"

void print_normal(const char *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
    write(1, "\n", 1);
}

void print_reverse(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    for (int j = i - 1; j >= 0; j--)
        write(1, &str[j], 1);
    write(1, "\n", 1);
}

void print_upper(const char *str)
{
    char c;

    for (int i = 0; str[i]; i++) {
        c = str[i] - 32 * (str[i] >= 'a' && str[i] <= 'z');
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

void print_42(const char *str)
{
    write(1, "42\n", 3);
}

void do_action(action_t action, const char *str)
{
    void (*actions[PRINT_COUNT])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    actions[action](str);
}
