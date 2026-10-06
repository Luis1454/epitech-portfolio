/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** buttons handling
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void append_button(button_t **head, char *label, int state, sfIntRect rect)
{
    button_t *new = malloc(sizeof(button_t));
    button_t *last = *head;

    new->label = my_strdup(label);
    new->state = state;
    new->rect = rect;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}

button_t *create_button(char *label, int state, sfIntRect rect)
{
    button_t *new = malloc(sizeof(button_t));

    new->label = my_strdup(label);
    new->state = state;
    new->rect = rect;
    new->next = NULL;
    return new;
}

button_t *get_buttons_by_name(button_t *head, char *name)
{
    button_t *current = head;

    while (current != NULL) {
        if (!my_strcmp(current->label, name))
            return (current);
        current = current->next;
    }
    return NULL;
}

void button_handling(game_t *game, char *name, char *menu)
{
    button_t *button = get_buttons_by_name(get_menu_by_id(game->menu,
    game->menu_id)->buttons, name);
    if (!button)
        return;
    if (is_in_rect(button->rect, game->mouse_pos)
    && game->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(game->sounds->click);
        game->menu_id = get_id_by_menu_name(game->menu, menu);
    }
}
