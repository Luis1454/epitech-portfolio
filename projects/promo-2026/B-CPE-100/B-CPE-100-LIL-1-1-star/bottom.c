/*
** EPITECH PROJECT, 2021
** bottom.c
** File description:
** function file
*/

#include <unistd.h>

void bottom_center(int size)
{
    int i;
    int j;
    int k;

    for (i = 0; i < size; i++) {
        put_char(*" ");
        for (j = 0; j < i+size*5-2; j++) {
            if (j == size-i-1 || j == size*6-3-size+i)
                put_char(*"*");
            else
                put_char(*" ");
        }
        put_char(*"\n");
    }
}

void bottom(int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < 4*size-i-1; j++) {
            if (j == i+size*2 || j == 4*size-i-2)
                put_char(*"*");
            else
                put_char(*" ");
        }
        put_char(*"\n");
    }
}