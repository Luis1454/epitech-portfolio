/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** task05
*/

#include <unistd.h>

void my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[argc - i - 1]);
    }

    return 0;
}
