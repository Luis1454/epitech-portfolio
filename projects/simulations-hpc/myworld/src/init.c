/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** init functions
*/

#include "../includes/my_world.h"

void init_screen(Screen *s)
{
    s->Xsize = 1920;
    s->Ysize = 1080;
    s->shutter = 60;
    s->mode.width = s->Xsize;
    s->mode.height = s->Ysize;
    s->mode.bitsPerPixel = 32;
}

void init_map(Map *map)
{
    int i = 0;
    map->i = 1;
    map->Xsize = 100;
    map->Ysize = 100;
    map->matrix = malloc(sizeof(Unit *) * (map->Xsize + 1));
    map->test = malloc(sizeof(sfVector3f *) * (map->Xsize + 1));
    map->cast_map = malloc(sizeof(sfVector2f *) * (map->Xsize + 1));
    map->b = malloc(sizeof(Brush));
    for (i = 0; i < map->Xsize; i++) {
        map->matrix[i] = malloc(sizeof(Unit) * (map->Ysize + 1));
        map->test[i] = malloc(sizeof(sfVector3f) * (map->Ysize + 1));
        for (int j = 0; j < map->Ysize; j++)
            map->test[i][j].z = 0;
        map->cast_map[i] = malloc(sizeof(sfVector2f) * (map->Ysize));
    }
    map->matrix[i] = NULL;
    map->cast_map[i] = NULL;
    sub_init_map(map, i);
}

void name_init_font(char **brushmenu)
{
    brushmenu[0] = "click";
    brushmenu[1] = "select";
    brushmenu[2] = "brush";
    brushmenu[3] = "smooth";
    brushmenu[4] = "eraser";
    brushmenu[5] = "dome";
    brushmenu[6] = "wave";
    brushmenu[7] = "polarized wave";
    brushmenu[8] = "pattern";
    brushmenu[9] = "random";
}

void init_font(Screen *s)
{
    sub_init_font(s);
    sub_ini_font(s);
    s->font->font = sfFont_createFromFile("fonts/doctor.ttf");
    s->font->text = sfText_create();
    s->font->box = sfText_create();
    s->font->box_bis = sfText_create();
    sfText_setFont(s->font->text, s->font->font);
    sfText_setColor(s->font->text, sfRed);
    sfText_setCharacterSize(s->font->text, 30);
    sfText_setPosition(s->font->text, (sfVector2f){30, 30});
    sfText_setFont(s->font->box, s->font->font);
    sfText_setColor(s->font->box, sfGreen);
    sfText_setCharacterSize(s->font->box, 30);
    sfText_setPosition(s->font->box, (sfVector2f){30, 90});
    sfText_setFont(s->font->box_bis, s->font->font);
    sfText_setColor(s->font->box_bis, sfBlue);
    sfText_setCharacterSize(s->font->box_bis, 30);
    sfText_setPosition(s->font->box_bis, (sfVector2f){30, 150});
}
