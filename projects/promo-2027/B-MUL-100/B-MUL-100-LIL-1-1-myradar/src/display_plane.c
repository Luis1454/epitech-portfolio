/*
** EPITECH PROJECT, 2022
** display_plane.c
** File description:
** display plane functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int display_plane_state(Screen *s, Plane p, sfVector2f pos)
{
    pos.x += 15;
    pos.y -= 2;
    sfText_setFont(s->text, s->font);
    sfText_setCharacterSize(s->text, 15);
    sfText_setColor(s->text, (sfColor){255, 255, 167, 255 /
    (((double)(get_planes_in_sky(s) + 1)) / 100)});
    add_text(s, s->text, p.name, (sfVector2f){pos.x, pos.y - 30});
    add_text(s, s->text, p.callsign, (sfVector2f){pos.x, pos.y - 15});
    add_text(s, s->text, p.flight->step, (sfVector2f){pos.x, pos.y});
    add_text(s, s->text, my_strcat(my_ftoa(p.speed), " kts"),
    (sfVector2f){pos.x, pos.y + 15});
    add_text(s, s->text, my_strcat(my_ftoa(p.pos.z)," ft"),
    (sfVector2f){pos.x, pos.y + 30});
    return 0;
}

static void global_sub_display_plane(Screen *s, int i, double f)
{
    sub_display_planes_a(s, i, f);
    sub_display_planes_b(s, i, f);
    sub_display_planes_c(s, i, f);
    if (!my_strcmp(s->plane[i].status, "FLYING")) {
        sub_display_planes_d(s, i);
        sub_display_planes_e(s, i);
        if (s->plane[i].pos.z > s->plane[i].flight->arrival.z
        && get_rate_to_tower(s, i) > s->plane[i].approach_rate) {
            s->plane[i].speed = s->plane[i].approach_speed;
            s->plane[i].pos.z -= s->plane[i].approach_rate;
            s->plane[i].flight->step = "DESCENT";
        }
        sfRenderWindow_drawRectangleShape(s->window, s->plane_rect, NULL);
    }
}

int display_planes(Screen *s)
{
    double f = 0.55;

    sfSprite_setScale(s->plane_sprite, (sfVector2f){f, f});
    sfSprite_setTexture(s->plane_sprite, s->plane_texture, sfTrue);
    sfSprite_setOrigin(s->plane_sprite, (sfVector2f){24, 24});
    sfRectangleShape_setFillColor(s->plane_rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(s->plane_rect, 1);
    for (int i = 0; i < s->nb_plane; i++) {
        global_sub_display_plane(s, i,
        s->plane[i].speed / FRAMERATE * s->timewarp / 10000 + 1);
        if (my_strcmp(s->plane[i].status, "CRASHED")
        && my_strcmp(s->plane[i].status, "PARKED"))
            sfRenderWindow_drawSprite(s->window, s->plane_sprite, NULL);
        update_path(s, i);
    }
    s->timestamp.t += s->time_in_sec * 500 * s->timewarp;
    return 0;
}
