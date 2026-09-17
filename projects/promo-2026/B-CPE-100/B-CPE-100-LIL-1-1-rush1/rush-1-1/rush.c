/*
** EPITECH PROJECT, 2021
** rush1
** File description:
** rush1
*/

#include <unistd.h>

void my_putchar(char c);

void first_and_last_line(int x)
{
    my_putchar('o');
    for (int i = 0; i < (x - 2); i++)
        my_putchar('-');
    my_putchar('o');
    my_putchar('\n');
}

void mids_lines(int x, int y)
{
    for (int j = 0; j < (y - 2); j++) {
        my_putchar('|');
        for (int k = 0; k < (x - 2); k++)
            my_putchar(' ');
        my_putchar('|');
        my_putchar('\n');
    }
}

void loop_excepts(int x, int y)
{
    my_putchar('o');
    if (x == 1 && y != 1) {
        for (int i = 0; i < (y - 2); i++) {
            my_putchar('\n');
            my_putchar('|');
        }
        my_putchar('o');
    }
    else if (y == 1 && x != 1) {
        for (int j = 0; j < (x - 2); j++)
            my_putchar('-');
        my_putchar('o');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    char const *str = "Invalide size\n";
    int p = 0;

    if (x < 1 || y < 1) {
        while (str[p] != '\0') {
            my_putchar(str[p]);
            p++;
        }
    }
    else if (x == 1 || y == 1)
        loop_excepts(x, y);
    else {
        first_and_last_line(x);
        mids_lines(x, y);
        first_and_last_line(x);
    }
}
