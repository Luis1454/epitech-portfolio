/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** get functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

node_t *get_balises_from_str(char *str)
{
    node_t *head = NULL;
    char *tmp = NULL;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == '<' && my_strncmp(&str[i], "<!", 2)
        && my_strncmp(&str[i], "<?", 2)) {
            tmp = my_strdup_to(&str[i], ">");
            append_node(&head, tmp);
        }
    }
    return head;
}

int get_args_occurences(node_t *head, char *arg)
{
    int i = 0;

    for (node_t *tmp = head; tmp; tmp = tmp->next)
        for (args_t *arg_tmp = tmp->args; arg_tmp; arg_tmp = arg_tmp->next)
            i += !my_strcmp(arg_tmp->value, arg);
    return i;
}

char *get_arg(args_t *head, char *arg)
{
        for (args_t *arg_tmp = head; arg_tmp; arg_tmp = arg_tmp->next)
            if (!my_strcmp(arg_tmp->var, arg))
                return arg_tmp->value;
    return NULL;
}

node_t *get_balise(node_t *head, char *balise, char *id)
{

    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, balise)
        && !my_strcmp(get_arg(tmp->args, "id"), id))
            return tmp;
    return NULL;
}

node_t *get_rectants(node_t **b)
{
    node_t *node = NULL;

    for (; *b && my_strcmp((*b)->name, "listOfReactants"); *b = (*b)->next);
    if (!(*b))
        return NULL;
    for (*b = (*b)->next; *b && my_strcmp((*b)->name,
    "/listOfReactants"); *b = (*b)->next)
        if (!my_strcmp((*b)->name, "speciesReference"))
            append_node(&node, (*b)->str);
    sort_node_by_var(&node, "species");
    return node;
}
