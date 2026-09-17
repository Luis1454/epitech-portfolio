/*
** EPITECH PROJECT, 2021
** my_print_alpha.c
** File
*/

#include <unistd.h>

int my_print_alpha(void) {
    int i;
    int ascii;
    for (i=0;i<26;i++) {
        ascii = 97+i;
        write(1, &ascii, 1);
    }

    write(1, "\n", 1);
}
