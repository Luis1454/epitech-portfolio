/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** core function
*/

#include <unistd.h>

void top(int size);

void top_center(int size);

void bottom_center(int size);

void bottom(int size);

void put_char(char c)
{
    write(1, &c, 1);
}

void horizontal_bar(int size)
{
    int v = size*6-1;
    int i;

    for (i = 0; i < v; i++) {
        if (i < size*2+1 || i > size*4-3)
            put_char(*"*");
        else
            put_char(*" ");
    }
    put_char(*"\n");
}

void star(unsigned int size)
{
    if (size > 1) {
        top(size);
        horizontal_bar(size);
        top_center(size);
        bottom_center(size);
        horizontal_bar(size);
        bottom(size);
    } else if (size == 1) {
        write(1, "   *\n", 5);
        write(1, "*** ***\n", 8);
        write(1, " *   *\n", 7);
        write(1, "*** ***\n", 8);
        write(1, "   *\n", 5);
    }
}
