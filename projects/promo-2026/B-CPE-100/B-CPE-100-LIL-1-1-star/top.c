/*
** EPITECH PROJECT, 2021
** top.c
** File description:
** function file
*/

#include <unistd.h>

void top(int size)
{
    int i;

    for (i = 0; i < size; i++) {
        for (int j = 0; j < 3*size-1-i; j++) {
            put_char(*" ");
        }
        put_char(*"*");
        if (i > 0) {
            for (int j = 0; j < i*2-1; j++) {
                put_char(*" ");
            }
            put_char(*"*");
        }

        put_char(*"\n");
    }
}

void top_center(int size)
{
    int i;
    int j;
    int k;

    for (i = 0; i < size-1; i++) {
        put_char(*" ");
        for (j = 0; j < -i+size*6-3; j++) {
            if (j == i || j == -i+size*6-4)
                put_char(*"*");
            else
                put_char(*" ");
        }
        put_char(*"\n");
    }
}