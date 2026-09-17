/*
** EPITECH PROJECT, 2022
** init_plane.c
** File description:
** init plane functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int init_plane_texture(Screen *s)
{
    s->plane_texture = sfTexture_createFromFile("texture/plane.png", NULL);
    s->plane_sprite = sfSprite_create();
    s->plane_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(s->plane_rect, (sfVector2f){20, 20});
    if (!s->plane_texture || !s->plane_sprite) {
        my_print_error("Error while loading the texture\n");
        return 1;
    }
    return 0;
}

void handle_metric_error(char *str, char *type)
{
    my_print_error("Error in the definition of the metric\n");
    my_print_error("Got : \"");
    my_print_error(str);
    my_print_error("\"\nBut expected : ");
    my_print_error(type);
    my_print_error(" <X> <Y> <Z>\n");
}

int check_metric(char **arr, char *str, char *type)
{
    char c = 'X';

    if (my_arrlen(arr) != 4) {
        handle_metric_error(str, type);
        my_print_error("Take exactly 3 arguments but ");
        my_putnbr_error(my_arrlen(arr) - 1);
        my_print_error(" found\n");
        return 1;
    }
    for (int j = 1; arr[j]; j++, c++)
        if (!only_contain("0123456789.", arr[j])) {
            my_printf("%s$\n", arr[j]);
            handle_metric_error(str, type);
            my_print_error("Argument ");
            write(2, &c, 1);
            my_print_error(" must be a positive number\n");
            return 1;
        }
    return 0;
}

int init_plane_metric(Screen *s, char *str)
{
    char **arr = my_str_to_array(str, "\n\t ");

    if (check_metric(arr, str, "AIRCRAFT_METRIC"))
        return 1;
    s->collide_metric = (vect_3d){my_getnbr(arr[1]),
    my_getnbr(arr[2]), my_getnbr(arr[3])};
    return 0;
}

int init_plane(Screen *s)
{
    if (init_pathmask(s))
        return 1;
    if (!s->nb_plane)
        return !!my_print_error("Error: no aircraft found\n");
    s->plane = malloc(sizeof(Plane) * s->nb_plane);
    if (!s->plane) {
        my_print_error("Error: malloc failed when allocating a plane\n");
        return 1;
    }
    for (int i = 0; i < s->nb_plane; i++) {
        s->plane[i].flight = malloc(sizeof(Flight));
        if (!s->plane[i].flight) {
            my_print_error("Error: malloc failed when allocating a flight\n");
            return 1;
        }
    }
    return 0;
}
