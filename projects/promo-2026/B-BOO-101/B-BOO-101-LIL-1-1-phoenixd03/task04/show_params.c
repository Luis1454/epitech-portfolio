/*
** EPITECH PROJECT, 2021
** show_params.c
** File description:
** print each parameter as a list
*/

#include "../includes/phoenix.h"
#include <unistd.h>

int main(int argc, char const **argv)
{
    for (int i = 0; i < argc; i++) {
        show_string(argv[i]);
        write(1, "\n", 1);
    }
    return 0;
}
