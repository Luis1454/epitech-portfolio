/*
** EPITECH PROJECT, 2021
** annimations.c
** File description:
** animations functions
*/

#include <stdlib.h>
#include "../../include/include.h"
#include "../../include/my.h"

sfColor *clear(sfColor *pixels, int Xsize, int Ysize);

sfColor *rd_pixel(sfColor *pixels, int Xsize, int Ysize, int t)
{
    if (!t)
        clear(pixels, Xsize, Ysize);
    for (int i = 0; i < rand() % 100000; i++)
        pixels[rand() % Ysize * Xsize + rand() % Xsize] =
        get_rgb(rand() % 255, rand() % 255, rand() % 255);
    return pixels;
}

sfColor *noise(sfColor *pixels, int Xsize, int Ysize, int t)
{
    for (int i = 0; i < Ysize; i++)
        for (int j = 0; j < Xsize; j++)
            pixels[i * Xsize + j] =
            get_rgb(rand() % t * 2, rand() % t * 3, rand() % t * 4);
    return pixels;
}

sfColor *netflix(sfColor *pixels, int Xsize, int Ysize, int t)
{
    int lux = 255;
    int r = rand() % Xsize;
    sfColor col = get_rgb(rand() % lux, rand() % lux, rand() % lux);
    if (t < 0)
        t -= 1;
    if (t < 2)
        t = 2;
    for (int i = 0; i < Ysize; i++) {
        for (int j = 0; j < Xsize; j++) {
            t = t * t > Xsize ? t % Xsize : t;
            pixels[i * Xsize + r] = col;
        }
    }
    return pixels;
}

sfColor *rain(sfColor *pixels, int Xsize, int Ysize)
{
    clear(pixels, Xsize, Ysize);
    for (int i = 0; i < Ysize; i++) {
        if (!(rand() % 100))
            pixels[i] =
            get_rgb(rand() % 255, rand() % 255, rand() % 255);
        else
            pixels[i] = get_rgb(0, 0, 0);
        for (int j = 0; j < Xsize; j++)
            pixels[i * Xsize] = pixels[j];
    }
    return pixels;
}
