/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-lemin-alexis.salaun
** File description:
** algo.c
*/

#include "lemin.h"

int start_by(char *str, char *start)
{
    int i = 0;

    if (!str || !start)
        return 0;
    for (; str[i] && start[i] && str[i] == start[i]; i++);
    return i == my_strlen(start);
}

void reset_visit(anthill_t *hill)
{
    for (room_t *tmp = hill->rooms; tmp; tmp = tmp->next)
        tmp->is_visited = 0;
}

int sub_loop(anthill_t *hill, int n, room_t *end)
{
    path_t *path = NULL;

    for (int i = 0; i < (int)hill->nb_ants; i++) {
        if (hill->ants[i].room == end || n - i <= 0)
            continue;
        path = get_path_by_id(hill->path, n - i);

        hill->ants[i].room->nb_ants--;
        hill->ants[i].room = path ? path->room : end;
        hill->ants[i].room->nb_ants++;
        my_printf("P%i-%s ", i + 1, hill->ants[i].room->name);
    }
    return 0;
}

int game_loop(anthill_t *hill)
{
    room_t *end = get_room_by_id(hill, hill->end_id);
    room_t *start = get_room_by_id(hill, hill->start_id);
    hill->path = find_path(hill, start, end, NULL);

    for (int n = 0; end->nb_ants < hill->nb_ants;) {
        n++;
        sub_loop(hill, n, end);
        my_printf("\n");
    }
    return 0;
}
