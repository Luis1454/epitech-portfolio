/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int main_loop(Screen *s)
{
    if (!(s->clock = sfClock_create()))
        return !!my_print_error("Error while initializing the clock\n");
    while (sfRenderWindow_isOpen(s->window) && !no_man_sky(s)) {
        while (sfRenderWindow_pollEvent(s->window, &s->event))
            s->event.type == sfEvtClosed ? sfRenderWindow_close(s->window) : 0;
        s->time = sfClock_getElapsedTime(s->clock);
        s->time_in_sec = s->time.microseconds / 1000000.0;
        if (s->time_in_sec > 1 / FRAMERATE) {
            sfRenderWindow_clear(s->window, (sfColor){0, 16, 0, 255});
            display_grid(s);
            reset_path_mask(s);
            display_pathmask(s);
            display_towers(s);
            display_planes(s);
            sfRenderWindow_display(s->window);
            sfClock_restart(s->clock);
        }
    }
    sfRenderWindow_destroy(s->window);
    return 0;
}

int sub_start_radar(Screen *s, sfVector2i res)
{
    s->map_ratio = MAX((s->limit.max.x - s->limit.min.x) / s->size.x,
    (s->limit.max.y - s->limit.min.y) / s->size.y);
    s->limit.min.x -= (1 - MARGIN_FACTOR) * s->size.x * s->map_ratio;
    s->limit.min.y -= (1 - MARGIN_FACTOR) * s->size.y * s->map_ratio;
    s->limit.max.x += (1 - MARGIN_FACTOR) * s->size.x * s->map_ratio;
    s->limit.max.y += (1 - MARGIN_FACTOR) * s->size.y * s->map_ratio;
    s->map_ratio /= MARGIN_FACTOR;
    sfRenderWindow_setFramerateLimit(s->window, FRAMERATE);
    main_loop(s);
    my_printf("\nSimulation ended after %i seconds\n",
    (int)(s->timestamp.t / s->timewarp));
    for (int i = 0; i < s->nb_plane;
    !my_strcmp(s->plane[i].status, "PARKED") ? res.x++ : res.y++, i++);
    my_printf("AIRCRAFT REPORT:\n\tLanded  : %i\n", res.x);
    my_printf("\tCrashed : %i\n", res.y);
    free(s->tower);
    free(s->plane);
    free(s);
    return 0;
}

int start_radar(const char *path)
{
    Screen *s = malloc(sizeof(Screen));
    if (s == NULL) {
        my_print_error("Error: malloc failed when allocating screen\n");
        return 84;
    }
    s->size = (sfVector2i){1920, 1080};
    s->limit.min = (sfVector2f){s->size.x, s->size.y};
    s->limit.max = (sfVector2f){0, 0};
    s->timestamp.t = 0;
    s->timewarp = 1;
    s->range_metric = (vect_3d){1, 1, 0};
    s->collide_metric = (vect_3d){1, 1, 0};
    if (check_map(s, path) || init_window(s,
    (sfVideoMode){s->size.x, s->size.y, 32}))
        return 84;
    return sub_start_radar(s, (sfVector2i){0, 0});
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_print_error("Error: invalid number of arguments (expected 1, got ");
        my_putnbr_error(ac - 1);
        my_print_error(")\n");
        my_print_error("Usage: ./my_radar [.rdr file]\n");
        return 84;
    }
    if (ac == 2 && (!my_strcmp(av[1], "-h") || !my_strcmp(av[1], "--help")))
        return display_file("README.usage");
    if (ac == 2 && (!my_strcmp(av[1], "-l") || !my_strcmp(av[1], "--legend")))
        return display_file("README.legend");
    return start_radar(av[1]);
}
