/*
** EPITECH PROJECT, 2021
** framebuffer.h
** File description:
** custom graphical include
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <SFML/Graphics.h>
#include <stdlib.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color);

typedef struct screen {
    sfRenderWindow *window;
    sfColor *pixels;
    sfVideoMode mode;
    sfEvent event;
    int **pos_field;
    int **life_map;
    int ***vect_field;
    sfTexture *texture;
    int Xsize;
    int Ysize;
    int shutter;
    int t;
    int seq;
} Screen;

#endif    /* FRAMEBUFFER_H_ */
