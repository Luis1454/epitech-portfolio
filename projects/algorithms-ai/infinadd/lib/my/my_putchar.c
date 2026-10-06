/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib test
*/

#include <unistd.h>

char my_putchar(char c)
{
    write(1, &c, 1);
}
