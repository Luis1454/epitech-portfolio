/*
** EPITECH PROJECT, 2022
** get_functions_b.c
** File description:
** get methods functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

button_t *get_button_by_name(button_t *b, char *name)
{
    while (b) {
        if (!my_strcmp(b->name, name))
            return b;
        if (get_button_by_name(b->child, name))
            return get_button_by_name(b->child, name);
        b = b->next;
    }
    return NULL;
}

button_t *get_button_by_state(button_t *b, int state)
{
    while (b) {
        if (b->state == state)
            return b;
        b = b->next;
    }
    return NULL;
}

int get_nb_child(button_t *b)
{
    int nb = 0;

    for (button_t *c = b; c; c = c->child)
        nb++;
    return nb;
}
