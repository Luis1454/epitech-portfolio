/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** display strings
*/

#include <unistd.h>

int my_strlen(const char *str);

int my_putchar(char c);

int my_putstr(char const *str)
{
    if (!str) {
        my_putstr("(null)");
        return 0;
    }
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return my_strlen(str);
}

int print_error(char const *str)
{
    if (!str) {
        print_error("(null)");
        return 0;
    }
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
    return my_strlen(str);
}
