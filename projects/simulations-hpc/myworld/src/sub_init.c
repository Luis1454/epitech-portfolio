/*
** EPITECH PROJECT, 2021
** sub_init.c
** File description:
** sub init functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

void sub_init_map(Map *map, int i)
{
    map->test[i] = NULL;
    map->b->brush_strength = 10;
    map->b->brush_color = sfWhite;
    map->b->brush_size = map->b->brush_strength;
    map->camera->zoom = 1;
    map->camera->Y = -15;
    map->b->nearest = (sfVector2i) {0, 0};
    map->b->brush_state = 1;
    map->b->dist = map->Xsize;
    map->b->select = (sfVector2i)
    {(int) (map->Xsize / 2),(int) (map->Ysize / 2)};
    map->X_pos = (sfVector3f)
    {map->Xsize / 2 * 10 - 100, map->Ysize / 2 * 10, 0};
    map->Y_pos = (sfVector3f)
    {map->Xsize / 2 * 10, map->Ysize / 2 * 10 - 100, 0};
    map->Z_pos = (sfVector3f)
    {map->Xsize / 2 * 10, map->Ysize / 2 * 10, 60};
    map->clock = sfClock_create();
}

void sub_ini_font(Screen *s)
{
    s->font->menu_tex = 0;
    s->font->brush_tex = 0;
    char **win_size_menu = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++) {
        win_size_menu[i] = malloc(sizeof(char) * 10);
    }
    win_size_menu[0] = "1920x1080";
    win_size_menu[1] = "800x600";
    s->font->winsize_text = win_size_menu;
    s->font->win_tex = 0;
    s->font->a_x = 30;
    s->font->a_y = 30;
}

void sub_init_font(Screen *s)
{
    char **textmenu = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++)
        textmenu[i] = malloc(sizeof(char) * 8);
    textmenu[0] = "MENU";
    textmenu[1] = "MENU";
    textmenu[2] = "MENU";
    s->font->menu_text = textmenu;
    char **brushmenu = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 2; i++)
        brushmenu[i] = malloc(sizeof(char) * 20);
    name_init_font(brushmenu);
    s->font->brush_text = brushmenu;
}
