/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** check if it's P or N
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0) {
        write(1, "N\n", 2);
        return 0;
    }
    write(1, "P\n", 2);
    return 0;
}
