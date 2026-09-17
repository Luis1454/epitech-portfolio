/*
** EPITECH PROJECT, 2021
** show_alphabet.c
** File description:
** print lowercases
*/

#include <unistd.h>

int show_alphabet(void)
{
    int n = '\n';

    for (int i = 97; i < 123; i++)
        write(1, &i, 1);
    write(1, &n, 1);
    return 0;
}
