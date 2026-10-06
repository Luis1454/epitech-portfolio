/*
** EPITECH PROJECT, 2023
** get_b.c
** File description:
** get functions
*/

#include "lemin.h"

room_t *get_room_by_id(anthill_t *hill, int id)
{
    room_t *tmp = hill->rooms;

    for (; tmp && tmp->id != id; tmp = tmp->next);
    return tmp;
}

room_t *get_room_by_name(anthill_t *hill, char *name)
{
    room_t *tmp = hill->rooms;

    for (; tmp && my_strcmp(tmp->name, name); tmp = tmp->next);
    return tmp;
}

ant_t *get_ant_by_room(anthill_t *hill, room_t *room)
{
    for (unsigned int i = 0; i < hill->nb_ants; i++)
        if (hill->ants[i].room == room)
            return &hill->ants[i];
    return NULL;
}

path_t *get_path_by_id(path_t *paths, int id)
{
    for (int i = 0; paths; paths = paths->next, i++)
        if (i == id)
            return paths;
    return NULL;
}
