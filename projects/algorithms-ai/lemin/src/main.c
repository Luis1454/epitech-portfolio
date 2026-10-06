/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** main for lemin
*/

#include "lemin.h"

int main(void)
{
    char **all_info = recup_file();

    if (all_info == NULL)
        return (84);
    init_tab(all_info);
    my_free_array(all_info);
    return (0);
}

void check_splits(anthill_t *hill, char *line)
{
    char **splits = my_str_to_word_array(line, ' ');
    if (my_array_len(splits) == 3 && all_args_are_digits(&splits[1])) {
        append_room(hill, splits[0],
        my_getnbr(splits[1]), my_getnbr(splits[2]));
        hill->nb_rooms++;
    }
    my_free_array(splits);
}

void store_pipe(anthill_t *hill, char *a, char *b)
{
    pipe_t *new = malloc(sizeof(pipe_t));
    pipe_t *tmp = hill->p;

    if (!new)
        return;
    new->in = my_strdup(a);
    new->out = my_strdup(b);
    if (!hill->p) {
        hill->p = new;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
}

void display_datas(anthill_t *hill)
{
    my_printf("#number_of_ants\n%d\n", hill->nb_ants);
    my_printf("#rooms\n");
    for (room_t *room = hill->rooms; room; room = room->next) {
        if ((unsigned int)room->id == hill->start_id)
            my_printf("##start\n");
        if ((unsigned int)room->id == hill->end_id)
            my_printf("##end\n");
        my_printf("%s %d %d\n", room->name, room->x, room->y);
    }
    my_printf("#tunnels\n");
    for (pipe_t *p = hill->p; p; p = p->next)
        my_printf("%s-%s\n", p->in, p->out);
    my_printf("#moves\n");
}
