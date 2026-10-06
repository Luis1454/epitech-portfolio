/*
** EPITECH PROJECT, 2021
** sub.c
** File description:
** sub functions for my_screensaver
*/

#include "../include/include.h"
#include "../include/my.h"

sfColor *clear(sfColor *pixels, int Xsize, int Ysize);

int animation(Screen s, int **life_map, sfSprite *sprite);

int get_anim(Screen s, sfSprite *sprite)
{
    while (sfRenderWindow_isOpen(s.window))
        s.t = animation(s, s.life_map, sprite) + 1;
}

int sub_main(Screen s, sfSprite *sprite)
{
    if (s.texture != NULL) {
        sfRenderWindow_setFramerateLimit(s.window, s.shutter);
        sfSprite_setTexture(sprite, s.texture, sfTrue);
        s.pixels = malloc(sizeof(sfColor) * s.Xsize * s.Ysize);
        s.pos_field = get_particles_field(s.Xsize, s.Ysize, 10000);
        s.life_map = get_particles_field(s.Xsize, s.Ysize, 60);
        s.vect_field = get_particles_vect_field(s.Xsize, s.Ysize);
        if (s.pixels != NULL)
            get_anim(s, sprite);
        free(s.pixels);
        free(s.vect_field);
        free(s.pos_field);
        free(s.life_map);
        sfTexture_destroy(s.texture);
    }
    return 1;
}

int sub_animation(Screen s)
{
    if (s.t < 3 * s.seq * s.shutter)
        noise(s.pixels, s.Xsize, s.Ysize, 3 * s.seq * s.shutter - s.t);
    else if (s.t < 4 * s.seq * s.shutter)
        netflix(s.pixels, s.Xsize, s.Ysize, s.t - 3 * s.seq * s.shutter);
    else {
        clear(s.pixels, s.Xsize, s.Ysize);
        s.t = 0;
    }
    return s.t;
}
