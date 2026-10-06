/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** buttons handling
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void append_menu(menu_t **head, char *label)
{
    menu_t *new = malloc(sizeof(menu_t));
    menu_t *last = *head;

    new->label = my_strdup(label);
    new->buttons = NULL;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}

menu_t *create_menu(char *label)
{
    menu_t *new = malloc(sizeof(menu_t));

    new->label = my_strdup(label);
    new->buttons = NULL;
    new->next = NULL;
    return new;
}

menu_t *get_menu_by_name(menu_t *head, char *name)
{
    menu_t *current = head;

    while (current != NULL) {
        if (!my_strcmp(current->label, name))
            return (current);
        current = current->next;
    }
    return NULL;
}

menu_t *get_menu_by_id(menu_t *head, int id)
{
    menu_t *c = head;

    for (int i = 0; c && i < id; i++)
        c = c->next;
    return c;
}

int get_id_by_menu_name(menu_t *head, char *name)
{
    int i = 0;

    for (menu_t *c = head; c; c = c->next, i++)
        if (!my_strcmp(c->label, name))
            return i;
    return 0;
}
