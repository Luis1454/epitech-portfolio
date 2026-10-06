/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** display_menu.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

sfColor get_color_by_name(char *name)
{
    if (!my_strcmp(name, "Life :"))
        return ((sfColor){255, 0, 0, 255});
    if (!my_strcmp(name, "Mana :"))
        return ((sfColor){167, 0, 255, 255});
    return ((sfColor){0, 0, 0, 0});
}

void display_button(game_t *game, button_t *button)
{
    sfRectangleShape_setOutlineThickness(game->rect, 3);
    sfRectangleShape_setOutlineColor(game->rect, (sfColor){105, 78, 52, 255});
    add_rect(game, (sfVector2f){button->rect.left, button->rect.top},
    (sfVector2f){button->rect.width, button->rect.height},
    is_in_rect(button->rect, game->mouse_pos) ? (sfColor){181, 159, 138, 255} :
    (sfColor){212, 193, 174, 255});
    add_text(game, game->text, button->label, (sfVector2f){button->rect.left +
    button->rect.width / 2.0, button->rect.top + button->rect.height / 2.0});
}

int display_menu(game_t *game)
{
    button_t *button = get_menu_by_id(game->menu, game->menu_id)->buttons;

    sfText_setColor(game->text, sfBlack);
    for (; button != NULL; button = button->next)
        display_button(game, button);
    return 0;
}
