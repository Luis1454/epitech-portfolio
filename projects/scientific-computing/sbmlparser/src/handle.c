/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** handle functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

int handle_rectants(node_t **b, char *id)
{
    node_t *node = get_rectants(b);

    my_printf("List of reactants of reaction %s\n", id);
    for (node_t *tmp = node; tmp; tmp = tmp->next)
        my_printf("--->%s\n", get_arg(tmp->args, "species"));
    return 0;
}

int handle_products(node_t **b, char *id)
{
    node_t *node = get_products(b);

    my_printf("List of products of reaction %s\n", id);
    for (node_t *tmp = node; tmp; tmp = tmp->next)
        my_printf("--->%s\n", get_arg(tmp->args, "species"));
    return 0;
}

int handle_i_flag(node_t *head, char *id, char *arg)
{
    int e_flag = !my_strcmp(arg, "-e") && arg;
    int json_flag = !my_strcmp(arg, "-json") && arg;

    if (arg && !e_flag && !json_flag)
        return 84;
    if (check_balise(head, id, "speciesReference", "species"))
        return json_flag ? display_json_compound(head, id) :
        display_compound(head, id);
    if (check_balise(head, id, "reaction", "id"))
        return display_reaction(head, id, e_flag, json_flag);
    return display_compartment(head, id);
}

int handle_e_flag(node_t *head, node_t *reaction)
{
    node_t *rectants = get_rectants(&head);
    node_t *products = get_products(&head);

    for (node_t *tmp = rectants; tmp; tmp = tmp->next)
        my_printf("%s%s %s", tmp != rectants && !tmp->next ? " + " : "",
        get_arg(tmp->args, "stoichiometry"), get_arg(tmp->args, "species"));
    my_printf(!my_strcmp(get_arg(reaction->args,
    "reversible"), "true") ? " <-> " : " -> ");
    for (node_t *tmp = products; tmp; tmp = tmp->next)
        my_printf("%s%s %s", tmp != products && !tmp->next ? " + " : "",
        get_arg(tmp->args, "stoichiometry"), get_arg(tmp->args, "species"));
    my_printf("\n");
    return 0;
}

node_t *get_products(node_t **b)
{
    node_t *node = NULL;

    for (; *b && my_strcmp((*b)->name, "listOfProducts"); *b = (*b)->next);
    if (!(*b))
        return NULL;
    for (*b = (*b)->next; *b && my_strcmp((*b)->name,
    "/listOfProducts"); *b = (*b)->next)
        if (!my_strcmp((*b)->name, "speciesReference"))
            append_node(&node, (*b)->str);
    sort_node_by_var(&node, "species");
    return node;
}
