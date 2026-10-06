/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

int display_compound(node_t *head, char *id)
{
    node_t *species = NULL;
    node_t *b = NULL;

    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, "reaction")
        && check_reaction(tmp))
            append_node(&b, tmp->str);
    sort_node_by_var(&b, "id");
    my_printf("List of reactions consuming or producing species %s", id);
    my_printf(" (quantities)\n");
    for (node_t *tmp = b; tmp; tmp = tmp->next) {
        species = get_balise(get_balise(head, "reaction",
        get_arg(tmp->args, "id")), "speciesReference", id);
        my_printf("--->%s (%s)\n", get_arg(tmp->args, "id"),
        get_arg(species->args, "stoichiometry"));
    }
    return 0;
}

int is_last_node(node_t *node, char *balise, char *id)
{
    for (node_t *tmp = node; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, balise)
        && !my_strcmp(get_arg(tmp->args, "id"), id))
            return 0;
    return 1;
}

int display_reaction(node_t *head, char *id, int e_flag, int json_flag)
{
    node_t *b = get_balise(head, "reaction", id);

    if (e_flag)
        return handle_e_flag(head, b);
    if (json_flag) {
        handle_json_rectants(&b);
        handle_json_products(&b);
        return 0;
    }
    if (handle_rectants(&b, id) || handle_products(&b, id))
        return 84;
    return 0;
}

void display_all_species(node_t *head)
{
    my_printf("List of species\n");
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        for (args_t *a_tmp = tmp->args; a_tmp; a_tmp = a_tmp->next)
            !my_strcmp(a_tmp->var, "name")
            && !my_strcmp(tmp->name, "species") ?
            my_printf("--->%s\n", a_tmp->value) : 0;
}

int display_compartment(node_t *head, char *arg)
{
    ll_t *ll_head = NULL;

    sort_node_by_var(&head, "name");
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        for (args_t *a_tmp = tmp->args; a_tmp; a_tmp = a_tmp->next)
            !my_strcmp(a_tmp->var, "compartment")
            && !my_strcmp(a_tmp->value, arg)
            ? append_ll_node(&ll_head, get_arg(tmp->args, "name")) : 0;
    if (!ll_head) {
        display_all_species(head);
        return 0;
    }
    my_printf("List of species in compartment %s\n", arg);
    for (ll_t *ll_tmp = ll_head; ll_tmp; ll_tmp = ll_tmp->next)
        my_printf("--->%s\n", ll_tmp->data);
    return 0;
}
