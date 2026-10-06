/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** linked list handling
*/

#include "lemin.h"

int append_room(anthill_t *hill, char *name, int x, int y)
{
    room_t *room = malloc(sizeof(room_t));
    room_t *tmp = hill->rooms;

    if (!room)
        return 1;
    room->name = my_strdup(name);
    room->id = hill->nb_rooms;
    room->is_end = 0;
    room->x = x;
    room->y = y;
    room->tunnels = NULL;
    room->nb_ants = 0;
    room->next = NULL;
    if (!tmp) {
        hill->rooms = room;
        return 2;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = room;
    return 0;
}

int append_tunnel(room_t *room, room_t *dest)
{
    tunnel_t *tunnel = malloc(sizeof(tunnel_t));
    tunnel_t *tmp = room->tunnels;

    if (!tunnel)
        return 1;
    tunnel->dest = dest;
    tunnel->next = NULL;
    if (!tmp) {
        room->tunnels = tunnel;
        return 2;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = tunnel;
    return 0;
}

int append_path(path_t **path, path_t *new)
{
    path_t *tmp = *path;

    if (!tmp) {
        *path = new;
        return 1;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
    return 0;
}
