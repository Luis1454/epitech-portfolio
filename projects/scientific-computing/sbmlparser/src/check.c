/*
** EPITECH PROJECT, 2023
** check.c
** File description:
** check functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

int sub_check_balise(node_t *tmp, char *balise, char *field, char *id)
{
    char *arg = NULL;

    if (!my_strcmp(tmp->name, balise)) {
        arg = get_arg(tmp->args, field);
        if (!my_strcmp(tmp->name, balise)
        && !my_strcmp(arg, id))
            return 1;
    }
    return 0;
}

int check_reaction(node_t *head)
{
    node_t *tmp = NULL;

    for (tmp = head; tmp && my_strcmp(tmp->name,
    "listOfReactants"); tmp = tmp->next);
    for (tmp = tmp->next; tmp && my_strcmp(tmp->name,
    "/listOfReactants"); tmp = tmp->next) {
        if (!my_strcmp(tmp->name, "speciesReference"))
            return 1;
    }
    return 0;
}

int sub_check_type(node_t *tmp, char *var, char *value)
{
    for (args_t *arg_tmp = tmp->args; arg_tmp; arg_tmp = arg_tmp->next)
        if (!my_strcmp(arg_tmp->var, var)
        && !my_strcmp(arg_tmp->value, value)
        && !my_strcmp(tmp->name, "species"))
            return 1;
    return 0;
}

int check_type(node_t *head, char *var, char *value)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (sub_check_type(tmp, var, value))
            return 1;
    return 0;
}
