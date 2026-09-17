/*
** EPITECH PROJECT, 2021
** my_print_comb.c
** File description:
**
*/
#include <unistd.h>

int my_print_comb(int n) {
    int i;
    int j;
    int k;
    int ascii1;
    int ascii2;
    int ascii3;
    for (i=0;i<=7;i++) {
        for (j=i+1;j<=8;j++) {
            for (k=j+1;k<=9;k++) {
                ascii1 = 48+i;
                ascii2 = 48+j;
                ascii3 = 48+k;
                write(1, &ascii1, 1);
                write(1, &ascii2, 1);
                write(1, &ascii3, 1);
                if (!(i == 7 && j == 8 && k == 9)) {
                    write(1, ", ", 2);
                }
            }
        }
    }
    write(1, "\n", 1);
}
