/*
** EPITECH PROJECT, 2022
** my_print_digits.c
** File description:
** print all digits
*/

#include <unistd.h>

int my_print_digits(void)
{
    char c[1] = "0";

    for (; c[0] <= '9'; c[0]++)
        write(1, c, 1);
    write(1, "\n", 1);

    return 0;
}
