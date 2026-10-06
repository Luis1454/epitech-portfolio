/*
** EPITECH PROJECT, 2022
** sub_display_plane.c
** File description:
** sub display planes functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void sub_display_planes_a(Screen *s, int i, double f)
{
    if (is_plane_at_start(s->plane[i], (vect_3d){f, f, f})) {
        if (!my_strcmp(s->plane[i].status, "PARKED")
        && s->plane[i].flight->departure_ts.t <= s->timestamp.t) {
            s->plane[i].status = "TAXIING";
            get_tower_from_icao(s, s->plane[i].flight->from)->nb_taxiing++;
            s->plane[i].waiting = 0;
        }
        if (!my_strcmp(s->plane[i].status, "TAXIING")
        && s->plane[i].flight->departure_ts.t <= s->timestamp.t
        && !s->plane[i].waiting) {
            s->plane[i].status = "FLYING";
            get_tower_from_icao(s, s->plane[i].flight->from)->nb_taxiing--;
        }
    }
}

void sub_display_planes_b(Screen *s, int i, double f)
{
    if (!my_strcmp(s->plane[i].status, "FLYING")
    && is_plane_at_dest(s->plane[i], (vect_3d){f, f, f})) {
        s->plane[i].flight->arrival_ts.t = s->timestamp.t;
        get_tower_from_icao(s, s->plane[i].flight->to)->nb_taxiing++;
    }
    if ((!my_strcmp(s->plane[i].status, "FLYING")
    || !my_strcmp(s->plane[i].status, "TAXIING")) && !s->plane[i].waiting
    && is_plane_at_dest(s->plane[i], (vect_3d){f, f, f})){
        s->plane[i].status = "TAXIING";
        s->plane[i].speed = 0;
        s->plane[i].pos = s->plane[i].flight->arrival;
        sfSprite_setPosition(s->plane_sprite, (sfVector2f)
        {(s->plane[i].flight->arrival.x - s->limit.min.x) / s->map_ratio - 5,
        (s->plane[i].flight->arrival.y - s->limit.min.y) / s->map_ratio});
        sfSprite_setRotation(s->plane_sprite, 0);
    }
}

void sub_display_planes_c(Screen *s, int i, double f)
{
    if (!my_strcmp(s->plane[i].status, "TAXIING")) {
        if (is_plane_at_start(s->plane[i], (vect_3d){f, f, f}))
            sfSprite_setPosition(s->plane_sprite, (sfVector2f)
            {(s->plane[i].pos.x - s->limit.min.x) / s->map_ratio,
            (s->plane[i].pos.y - s->limit.min.y) / s->map_ratio});
        else if (is_plane_at_dest(s->plane[i], (vect_3d){f, f, f})
        && s->plane[i].flight->arrival_ts.t + TAXIING_TIME <= s->timestamp.t) {
            s->plane[i].status = "PARKED";
            get_tower_from_icao(s, s->plane[i].flight->to)->nb_taxiing--;
        }
        s->plane[i].speed = 0;
    }
}

void sub_display_planes_d(Screen *s, int i)
{
    sfRectangleShape_setOutlineColor(s->plane_rect,
    set_color_by_distance(s, i));
    display_plane_state(s, s->plane[i], (sfVector2f)
    {(s->plane[i].pos.x - s->limit.min.x) / s->map_ratio,
    (s->plane[i].pos.y - s->limit.min.y) / s->map_ratio});
    s->plane[i].flight->heading = atan2(s->plane[i].flight->arrival.y -
    s->plane[i].pos.y, s->plane[i].flight->arrival.x - s->plane[i].pos.x);
    s->plane[i].flight->heading -= (get_pythagore_3d(s->plane[i].pos,
    s->plane[i].flight->arrival, (vect_3d){1, 1, 0}) <
    MAX(get_tower_from_icao(s, s->plane[i].flight->to)->range / 5, 30)
    && (get_tower_from_icao(s, s->plane[i].flight->to)->nb_taxiing >=
    get_tower_from_icao(s, s->plane[i].flight->to)->capacity
    || !has_priority(s, i)) ? 90 : FLIGHT_EXCENTRICITY) * PI / 180;
    sfSprite_setRotation(s->plane_sprite,
    s->plane[i].flight->heading * 180 / PI + 90);
    s->plane[i].pos.y += s->plane[i].speed * sin(s->plane[i].flight->heading)
    / s->map_ratio / 3600 / FRAMERATE * s->timewarp;
    s->plane[i].pos.x += s->plane[i].speed * cos(s->plane[i].flight->heading)
    / s->map_ratio / 3600 / FRAMERATE * s->timewarp;
}

void sub_display_planes_e(Screen *s, int i)
{
    s->plane[i].flight->heading < atan2(s->plane[i].flight->arrival.y -
    s->plane[i].pos.y, s->plane[i].flight->arrival.x - s->plane[i].pos.x) -
    90 * PI / 180 ? s->plane[i].flight->step = "CIRCLING" : 0;
    sfSprite_setPosition(s->plane_sprite, (sfVector2f)
    {(s->plane[i].pos.x - s->limit.min.x) / s->map_ratio,
    (s->plane[i].pos.y - s->limit.min.y) / s->map_ratio});
    sfRectangleShape_setPosition(s->plane_rect, (sfVector2f)
    {(s->plane[i].pos.x - s->limit.min.x) / s->map_ratio - 10,
    (s->plane[i].pos.y - s->limit.min.y) / s->map_ratio - 10});
    get_plane_collide(s, i);
    s->plane[i].flight->travelled_dist += s->plane[i].speed;
    if (!my_strcmp(s->plane[i].flight->step, "CLIMB")
    && s->plane[i].pos.z < s->plane[i].cruise_alt) {
        s->plane[i].speed = s->plane[i].cruise_speed;
        s->plane[i].pos.z += s->plane[i].climb_rate;
    }
    if (s->plane[i].pos.z >= s->plane[i].cruise_alt) {
        s->plane[i].flight->step = "CRUISE";
        s->plane[i].pos.z = s->plane[i].cruise_alt;
    }
}
