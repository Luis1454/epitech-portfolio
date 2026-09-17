/*
** EPITECH PROJECT, 2022
** swap_endian_color.c
** File description:
** endianless transform;
*/

#include "include/my.h"
#include "include/struct.h"

int swap_endian_color(int color)
{
    union color c;
    int r = color >> 24;
    int g = (color << 8) >> 24;
    int b = (color << 16) >> 24;
    int a = (color << 24) >> 24;

    c.rgba[0] = a;
    c.rgba[1] = r;
    c.rgba[2] = g;
    c.rgba[3] = b;
    return c.val;
}
