/*
** EPITECH PROJECT, 2023
** image.c
** File description:
** image functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int create_new(screen_t *s, sfVector2i size, char *file)
{
    s->image = malloc(sizeof(image_t));
    if (!s->image)
        return 1;
    s->image->sprite = sfSprite_create();
    s->image->texture = sfTexture_create(size.x, size.y);
    if (!s->image->sprite || !s->image->texture)
        return 1;
    s->image->size = sfTexture_getSize(s->image->texture);
    sfSprite_setTexture(s->image->sprite, s->image->texture, sfTrue);
    s->image->pixels = malloc(sizeof(sfColor)
    * s->image->size.x * s->image->size.y);
    for (unsigned int i = 0; i < s->image->size.x * s->image->size.y; i++)
        s->image->pixels[i] = sfTransparent;
    if (s->file)
        free(s->file);
    s->file = my_strdup(file ? file : "untitled.jpg");
    sfRenderWindow_setTitle(s->window, s->file);
    return 0;
}

int load_image(screen_t *s)
{
    s->image = malloc(sizeof(image_t));
    if (!s->image)
        return 1;
    s->image->sprite = sfSprite_create();
    s->image->texture = sfTexture_createFromFile(s->file, NULL);
    if (!s->image->sprite || !s->image->texture)
        return 1;
    s->image->size = sfTexture_getSize(s->image->texture);
    sfSprite_setTexture(s->image->sprite, s->image->texture, sfTrue);
    s->image->pixels = malloc(sizeof(sfUint8)
    * s->image->size.x * s->image->size.y * 4);
    if (!s->image->pixels)
        return 1;
    return 0;
}

int destroy_image(image_t *image)
{
    if (!image)
        return 1;
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    free(image->pixels);
    free(image);
    return 0;
}

int save_image(screen_t *s)
{
    if (!s->image->img)
        return 1;
    s->image->img = sfImage_createFromPixels(s->image->size.x,
    s->image->size.y, (const sfUint8 *)s->image->pixels);
    sfImage_saveToFile(s->image->img, s->file ? s->file : "untitled.jpg");
    return 0;
}
