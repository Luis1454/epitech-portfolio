/*
** EPITECH PROJECT, 2021
** show_string.c
** File description:
** print a string
*/

#include <unistd.h>

int my_strlen(char *str);

int show_string(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
