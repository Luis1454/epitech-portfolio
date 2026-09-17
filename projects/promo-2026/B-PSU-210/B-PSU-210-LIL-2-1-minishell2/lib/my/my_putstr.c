/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int count = 0;

    if (str == NULL) {
        write(1, "(null)", 7);
        return 0;
    }
    while (str[count]) {
        my_putchar(str[count]);
        count++;
    }
    return 1;
}
