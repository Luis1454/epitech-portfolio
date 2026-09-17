/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** sbml utils
*/

#include "../include/my.h"
#include "../include/sbml.h"

int get_first_alphanum(char *str)
{
    int i = 0;

    for (; str[i] && !my_char_isalpha(str[i]) && !my_char_isnum(str[i]); i++);
    return i;
}

void skip_to_next_balise(int *i, char *str)
{
    if (!str || *i >= my_strlen(str))
        return;
    for (; str[*i] && my_strncmp(&str[*i], ">", 1); (*i)++);
    for (; str[*i] && my_strncmp(&str[*i], "<", 1); (*i)++);
}

int check_balise(node_t *head, char *id, char *balise, char *field)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (sub_check_balise(tmp, balise, field, id))
            return 1;
    return 0;
}

void sort_node(node_t **head)
{
    node_t *tmp = *head;
    node_t *tmp2 = NULL;

    for (; tmp; tmp = tmp->next)
        for (tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
            my_strcmp(tmp->str, tmp2->str) > 0 ?
            swap_nodes(tmp, tmp2) : 0;
}

int get_name_pos(char *str)
{
    int i = 0;

    for (; str[i] && !my_char_isalpha(str[i])
    && !my_char_isnum(str[i]) && str[i] != '/'; i++);

    return i;
}
