/*
** EPITECH PROJECT, 2022
** get_functions_a.c
** File description:
** get methods functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

double get_pythagore(sfVector2f a, sfVector2f b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double get_min_dist(sfVector2f point, sfVector2f *points, int size)
{
    double min = -1;
    double dist = 0;

    for (int i = 0; i < size; i++) {
        dist = get_pythagore(point, points[i]);
        if (min == -1 || dist < min)
            min = dist;
    }
    return min;
}

struct dirent *get_file_from_pos(screen_t *s, linked_list_t *l, sfVector2f pos)
{
    int col = 15;
    int space = 20;
    int tab = 120;
    int index = 0;
    int len = my_list_size(l);
    linked_list_t *tmp = l;
    sfVector2i pos_in_grid = (sfVector2i){(s->mouse_pos.x
    - pos.x) / tab, (s->mouse_pos.y - pos.y - 40) / space};

    index = pos_in_grid.x * col + pos_in_grid.y;
    if (index >= 0 && index < len && pos_in_grid.x >= 0
    && pos_in_grid.y >= 0 && pos_in_grid.x <= len / col
    && pos_in_grid.y < col) {
        for (tmp = l; tmp && index--; tmp = tmp->next);
        if (tmp)
            return (struct dirent *)tmp->data;
    }
    return NULL;
}

double get_value_from_pos(slider_t *slider, sfVector2i pos)
{
    double ratio = (double)(pos.x - slider->pos.x) / (double)slider->size.x;
    double value = slider->min + (slider->max - slider->min) * ratio;

    return value;
}

void get_empty_pattern(screen_t *s, int margin, sfVector2f pos, sfVector2f size)
{
    sfColor A = sfColor_fromRGBA(0, 0, 0, 63);
    sfColor B = sfColor_fromRGBA(255, 255, 255, 63);

    sfRectangleShape_setOutlineThickness(s->rect, 0);
    for (int i = 0; i < size.x / margin; i++)
        for (int j = 0; j < size.y / margin; j++) {
            sfRectangleShape_setPosition(s->rect, (sfVector2f)
            {pos.x + i * margin, pos.y + j * margin});
            sfRectangleShape_setSize(s->rect, (sfVector2f){margin, margin});
            sfRectangleShape_setFillColor(s->rect, (i + j) % 2 == 0 ? A : B);
            sfRenderWindow_drawRectangleShape(s->window, s->rect, NULL);
        }
}
