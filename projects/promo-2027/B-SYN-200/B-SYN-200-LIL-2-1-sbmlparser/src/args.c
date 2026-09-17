/*
** EPITECH PROJECT, 2023
** args.c
** File description:
** args nodes handling
*/

#include "../include/my.h"
#include "../include/sbml.h"

void append_arg(args_t **head, char *str)
{
    args_t *new = malloc(sizeof(args_t));
    args_t *tmp = *head;
    int len = 0;

    new->var = my_strdup_to(str, "=");
    len = my_strlen(new->var);
    new->var[len - 1] = 0;
    new->value = my_strndup(&str[len + 1], my_strlen_to(&str[len + 1], "\""));
    new->next = NULL;
    if (!(*head)) {
        *head = new;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
}

void sort_args(args_t **head)
{
    args_t *tmp = *head;
    args_t *tmp2 = NULL;

    for (; tmp; tmp = tmp->next)
        for (tmp2 = tmp->next; tmp2; tmp2 = tmp2->next) {
            my_strcmp(tmp->var, tmp2->var) > 0 ?
            my_swap((int *)&tmp->value, (int *)&tmp2->value) : 0;
            my_strcmp(tmp->var, tmp2->var) > 0 ?
            my_swap((int *)&tmp->var, (int *)&tmp2->var) : 0;
        }
}

int get_nb_args(args_t *head)
{
    int i = 0;

    for (; head; head = head->next, i++);
    return i;
}

args_t *get_args(char *str)
{
    args_t *head = NULL;
    int i = 0;

    for (; str[i] && str[i] != ' '; i++);
    for (i++; i < my_strlen(str); i++) {
        if (str[i] == ' ')
            continue;
        append_arg(&head, &str[i]);
        for (; str[i] && str[i] != '"'; i++);
        for (i++; str[i] && str[i] != '"'; i++);
        for (; str[i] && str[i] != ' '; i++);
    }
    return head;
}
