/*
** EPITECH PROJECT, 2023
** get_a.c
** File description:
** get functions
*/

#include "lemin.h"

static path_t *sub_find(room_t *end, path_t *path, path_t *new, tunnel_t *tmp)
{
    if (tmp->dest->is_visited < 2 && tmp->dest == end) {
        new = malloc(sizeof(path_t));
        if (!new)
            return NULL;
        new->room = tmp->dest;
        new->next = NULL;
        append_path(&path, new);
        return path;
    }
    return NULL;
}

static void init_find(room_t *room, path_t *new, path_t **path)
{
    room->is_visited = 1;
    new->room = room;
    new->next = NULL;
    append_path(path, new);
}

path_t *find_path(anthill_t *hill, room_t *room, room_t *end, path_t *path)
{
    path_t *new = malloc(sizeof(path_t));
    path_t *tmp_path;
    path_t *out;

    if (!new)
        return NULL;
    init_find(room, new, &path);
    if (room == end)
        return path;
    for (tunnel_t *tmp = room->tunnels; tmp; tmp = tmp->next)
        if ((out = sub_find(end, path, new, tmp)))
            return out;
    for (tunnel_t *tmp = room->tunnels; tmp; tmp = tmp->next) {
        if (!tmp->dest->is_visited
        && (tmp_path = find_path(hill, tmp->dest, end, path)))
            return tmp_path;
    }
    room->is_visited = 2;
    return NULL;
}
