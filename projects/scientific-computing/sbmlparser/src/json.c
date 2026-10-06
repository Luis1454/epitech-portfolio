/*
** EPITECH PROJECT, 2023
** json.c
** File description:
** json formatting functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

int handle_json_rectants(node_t **b)
{
    node_t *node = get_rectants(b);

    my_printf("{\n\"listOfReactants\": [\n");
    for (node_t *tmp = node; tmp; tmp = tmp->next) {
        my_printf("\t{\n");
        for (args_t *tmp2 = tmp->args; tmp2; tmp2 = tmp2->next) {
            my_printf("\t\t\"%s\": \"%s\"", tmp2->var, tmp2->value);
            my_printf(tmp2->next ? ",\n" : "\n");
        }
        my_printf("\t}");
        my_printf(tmp->next ? ",\n" : "\n");
    }
    my_printf("],\n");
    return 0;
}

int handle_json_products(node_t **b)
{
    node_t *node = get_products(b);

    my_printf("\"listOfProducts\": [\n");
    for (node_t *tmp = node; tmp; tmp = tmp->next) {
        my_printf("\t{\n");
        for (args_t *tmp2 = tmp->args; tmp2; tmp2 = tmp2->next) {
            my_printf("\t\t\"%s\": \"%s\"", tmp2->var, tmp2->value);
            my_printf(tmp2->next ? ",\n" : "\n");
        }
        my_printf("\t}");
        my_printf(tmp->next ? ",\n" : "\n");
    }
    my_printf("]\n}\n");
    return 0;
}

int display_json_compound(node_t *head, char *id)
{
    node_t *node = get_balise(head, "species", id);

    sub_json_compound_a(head, node);
    sub_json_compound_b(head, id);
    my_printf("],\n\"listOfReactions\": [\n");
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        !my_strcmp(tmp->name, "reaction") ? my_printf("\t{\n") : 0;
        for (args_t *a_tmp = tmp->args; a_tmp; a_tmp = a_tmp->next) {
            !my_strcmp(tmp->name, "reaction") ?
            my_printf("\t\t\"%s\": \"%s\"", a_tmp->var, a_tmp->value) : 0;
            !my_strcmp(tmp->name, "reaction") ? my_printf("%s",
            a_tmp->next ? ",\n" : "\n") : 0;
        }
        !my_strcmp(tmp->name, "reaction") ?
        my_printf("\t}%s", tmp->next ? ",\n" : "\n") : 0;
    }
    return 0;
}
