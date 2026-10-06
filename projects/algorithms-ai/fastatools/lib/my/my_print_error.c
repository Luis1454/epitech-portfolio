/*
** EPITECH PROJECT, 2022
** my_print_error.c
** File description:
** display error
*/

#include <unistd.h>

static void my_char_error(char c)
{
    write(2, &c, 1);
}

int my_print_error(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_char_error(str[i]);
    return 0;
}
