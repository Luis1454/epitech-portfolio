/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for my_screensaver
*/

#include "../include/include.h"
#include "../include/my.h"

int sub_animation(Screen s);

int sub_main(Screen s, sfSprite *sprite);

sfColor *clear(sfColor *pixels, int Xsize, int Ysize)
{
    for (int i = 0; i < Ysize; i++)
        for (int j = 0; j < Xsize; j++)
            pixels[i * Xsize + j] = get_rgb(0, 0, 0);
    return pixels;
}

int animation(Screen s, int **life_map, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(s.window, &s.event))
        if (s.event.type == sfEvtClosed)
            sfRenderWindow_close(s.window);
    if (s.t < s.seq * s.shutter)
        life_game(s.pixels, life_map, s.Xsize, s.Ysize);
    else if (s.t < 2 * s.seq * s.shutter)
        rd_pixel(s.pixels, s.Xsize, s.Ysize, s.t - s.seq * s.shutter);
    else
        s.t = sub_animation(s);
    sfRenderWindow_clear(s.window, sfBlack);
    sfTexture_updateFromPixels(s.texture, (sfUint8*) s.pixels,
        s.Xsize, s.Ysize, 0, 0);
    sfRenderWindow_drawSprite(s.window, sprite, NULL);
    sfRenderWindow_display(s.window);
    return s.t++;
}

Screen init(Screen s)
{
    s.Xsize = 1280;
    s.Ysize = 720;
    s.shutter = 60;
    s.t = 0;
    s.seq = 15;
    s.mode.width = s.Xsize;
    s.mode.height = s.Ysize;
    s.mode.bitsPerPixel = 32;
    s.event;
    return s;
}

int main(int argc, char *argv)
{
    Screen s = init(s);

    if (argc != 2)
        return 84;
    sfSprite *sprite = sfSprite_create();
    s.window =
    sfRenderWindow_create(s.mode, "my_screensaver", sfResize | sfClose, NULL);
    if (s.window == NULL)
        return EXIT_FAILURE;
    else {
        s.texture = sfTexture_create(s.Xsize, s.Ysize);
        sub_main(s, sprite);
        sfRenderWindow_destroy(s.window);
        sfSprite_destroy(sprite);
        return EXIT_SUCCESS;
    }
}
