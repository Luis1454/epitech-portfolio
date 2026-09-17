/*
** EPITECH PROJECT, 2021
** features.c
** File description:
** utils
*/

#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str);

int pwr(int num, int pwr);

int get_num_len(long long int num)
{
    int nb = 0;

    while (num > 9) {
        num /= 10;
        nb++;
    }

    return nb + 1;
}

int get_base(long long int num, int base)
{
    int tmp;
    int out;

    if (base < 10) {
        tmp = 1;
        out = 0;
        while (num) {
            out += (num % base) * tmp;
            tmp *= 10;
            num /= base;
        }
        return out;
    } else
        return 0;
}

char *get_hex(unsigned int num, int state)
{
    char *out;
    int len = 0;
    int tmp = num;
    int i;

    for (i = 0; num > 0; num /= 16, len++);
    out = malloc(sizeof(char) * (len + 1));
    for (i = 0, num = tmp; num; i++) {
        tmp = num % 16;
        num /= 16;
        if (tmp < 10)
            out[i] = tmp + '0';
        else if (state)
            out[i] = tmp + 'A' - 10;
        else
            out[i] = tmp + 'a' - 10;
    }
    out[i] = 0;
    out = my_revstr(out);
    return out;
}
