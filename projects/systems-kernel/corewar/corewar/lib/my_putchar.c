/*
** EPITECH PROJECT, 2022
** Tek1
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void putchar_error(char c)
{
    write(2, &c, 1);
}
