/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** init functions
*/

#include "lemin.h"

int init_tab(char **raw)
{
    anthill_t *hill = malloc(sizeof(anthill_t));
    if (!hill)
        return 1;
    init_rooms(hill, raw);
    return 0;
}

int init_tunnels(anthill_t *hill, char **raw)
{
    hill->nb_tunnels = 0;
    for (int i = 1; raw[i]; i++) {
        if (start_by(raw[i], "#"))
            continue;
        char **splits = my_str_to_word_array(raw[i], '-');
        if (my_array_len(splits) == 2) {
            hill->nb_tunnels++;
            append_tunnel(get_room_by_name(hill,
            splits[0]), get_room_by_name(hill, splits[1]));
            append_tunnel(get_room_by_name(hill,
            splits[1]), get_room_by_name(hill, splits[0]));
            store_pipe(hill, splits[0], splits[1]);
        }
        my_free_array(splits);
    }
    return 0;
}

int init_ants(anthill_t *hill)
{
    hill->ants = malloc(sizeof(ant_t) * hill->nb_ants);
    if (!hill->ants)
        return 1;
    for (int i = 0; i < (int)hill->nb_ants; i++) {
        hill->ants[i].id = i;
        hill->ants[i].room = get_room_by_id(hill, hill->start_id);
    }
    return 0;
}

int init_rooms(anthill_t *hill, char **raw)
{
    hill->nb_rooms = 0;
    hill->nb_ants = my_getnbr(raw[0]);
    hill->rooms = NULL;
    for (int i = 1; raw[i]; i++) {
        if (start_by(raw[i], "##start"))
            hill->start_id = hill->nb_rooms;
        if (start_by(raw[i], "##end"))
            hill->end_id = hill->nb_rooms;
        if (start_by(raw[i], "#"))
            continue;
        check_splits(hill, raw[i]);
    }
    init_tunnels(hill, raw);
    room_t *start = get_room_by_id(hill, hill->start_id);
    start->is_occupied = 1;
    start->is_visited = 1;
    start->nb_ants = hill->nb_ants;
    init_ants(hill);
    display_datas(hill);
    return game_loop(hill);
}
