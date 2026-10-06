/*
** EPITECH PROJECT, 2023
** slider.c
** File description:
** slider functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void sub_slider(screen_t *s, slider_t *slider, int is_float, char *str)
{
    display_text(s, str, (sfVector2f){slider->pos.x,
    slider->pos.y + slider->size.y}, sfBlack);
    free(str);
    str = my_ftoa(slider->max);
    display_text(s, str, (sfVector2f){slider->pos.x +
    slider->size.x - 10, slider->pos.y + slider->size.y}, sfBlack);
    free(str);
    str = my_ftoa(is_float ? slider->value : (int)slider->value);
    display_text(s, str, (sfVector2f){slider->pos.x +
    slider->size.x / 2 - 10, slider->pos.y + slider->size.y}, sfBlack);
    free(str);
}

slider_t *create_slider(sfVector2f pos,
sfVector2f size, sfVector2f limits, char *name)
{
    slider_t *slider = malloc(sizeof(slider_t));

    if (!slider)
        return NULL;
    slider->pos = pos;
    slider->size = size;
    slider->value = limits.x + (limits.y - limits.x) / 2;
    slider->min = limits.x;
    slider->max = limits.y;
    slider->name = my_strdup(name);
    return slider;
}

void destroy_slider(slider_t *slider)
{
    if (slider)
        free(slider);
}

void set_slider_value(slider_t *slider, double value)
{
    if (value < slider->min)
        slider->value = slider->min;
    else if (value > slider->max)
        slider->value = slider->max;
    else
        slider->value = value;
}

int is_in_slider(screen_t *s, slider_t *slider)
{
    return is_in_box((frame_t){slider->pos, slider->size},
    (sfVector2f){s->mouse_pos.x, s->mouse_pos.y});
}
