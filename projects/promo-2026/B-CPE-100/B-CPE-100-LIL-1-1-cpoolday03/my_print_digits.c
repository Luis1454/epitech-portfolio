/*
** EPITECH PROJECT, 2021
** my_print_digits.c
** File
*/

#include <unistd.h>

int my_print_digits(void) {
    int i;
    int ascii;
    for(i=0;i<=9;i++) {
        ascii = 48+i;
        write(1, &ascii, 1);
    }

    write(1, "\n", 1);
}
