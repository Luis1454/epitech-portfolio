/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** tools functions
*/

#include "../../include/include.h"
#include "../../include/my.h"

sfColor get_rgb(sfUint8 r, sfUint8 g, sfUint8 b)
{
    sfColor c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = 255;
    return c;
}
