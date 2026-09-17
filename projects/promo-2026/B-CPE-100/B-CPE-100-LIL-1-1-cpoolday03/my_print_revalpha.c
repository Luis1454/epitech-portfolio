/*
** EPITECH PROJECT, 2021
** my_print_alpha.c
** File
*/

#include <unistd.h>
int my_print_revalpha(void) {
    int i;
    int ascii;
    for (i=0;i<26;i++) {
        ascii = 96+26-i;
        write(1, &ascii, 1);
    }
    write(1, "\n", 1);
}
