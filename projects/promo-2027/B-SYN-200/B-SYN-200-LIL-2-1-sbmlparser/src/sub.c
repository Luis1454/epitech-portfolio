/*
** EPITECH PROJECT, 2023
** sub.c
** File description:
** sub_functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

static void sub_compound_a(node_t *tmp)
{
    for (args_t *a_tmp = tmp->args; a_tmp; a_tmp = a_tmp->next) {
        my_printf("\t\t\"%s\": \"%s\"", a_tmp->var, a_tmp->value);
        my_printf("%s", a_tmp->next ? ",\n" : "\n");
    }
}

void sub_json_compound_a(node_t *head, node_t *node)
{
    my_printf("{\n\"listOfCompartments\": [\n");
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (!my_strcmp(get_arg(tmp->args, "id"), get_arg(node->args,
        "compartment")) && !my_strcmp(tmp->name, "compartment")) {
            my_printf("\t{\n");
            sub_compound_a(tmp);
            my_printf("\t}%s", !is_last_node(tmp->next,
            "compartment", get_arg(tmp->args, "id")) ? ",\n" : "\n");
        }
}

static void sub_compound_b(node_t *tmp)
{
    for (args_t *a_tmp = tmp->args; a_tmp; a_tmp = a_tmp->next) {
        !my_strcmp(tmp->name, "species") ?
        my_printf("\t\t\"%s\": \"%s\"", a_tmp->var, a_tmp->value) : 0;
        !my_strcmp(tmp->name, "species") ? my_printf("%s",
        a_tmp->next ? ",\n" : "\n") : 0;
    }
}

void sub_json_compound_b(node_t *head, char *id)
{
    my_printf("],\n\"listOfSpecies\": [\n");
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        if (!my_strcmp(id, get_arg(tmp->args, "id"))) {
            !my_strcmp(tmp->name, "species") ? my_printf("\t{\n") : 0;
            sub_compound_b(tmp);
            !my_strcmp(tmp->name, "species") ?
            my_printf("\t}%s", tmp->next ? ",\n" : "\n") : 0;
        }
    }
}

void sort_node_by_var(node_t **head, char *var)
{
    node_t *tmp = *head;
    node_t *tmp2 = NULL;

    for (; tmp; tmp = tmp->next)
        for (tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
            my_strcmp(get_arg(tmp->args, var),
            get_arg(tmp2->args, var)) > 0 ?
            swap_nodes(tmp, tmp2) : 0;
}
