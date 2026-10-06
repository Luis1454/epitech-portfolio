/*
** EPITECH PROJECT, 2023
** others.c
** File description:
** others functions
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"
#include "../../include/mylist.h"
#include "../../include/handling.h"
#include "../../include/my_macro_abs.h"
#include <dirent.h>
#include <sys/types.h>

int cmp_dirent(struct dirent *a, struct dirent *b)
{
    if (!a || !b)
        return 0;
    if (a->d_type == 4 && b->d_type != 4)
        return -1;
    if (a->d_type != 4 && b->d_type == 4)
        return 1;
    return my_strcmp(a->d_name, b->d_name);
}

linked_list_t *get_folder(game_t *game, char *path)
{
    struct dirent *entry;
    linked_list_t *list = NULL;
    int i = 0;

    if (!(game->dir = opendir(path)))
        return NULL;
    for (; (entry = readdir(game->dir)) != NULL; i++) {
        if (i)
            append_node(&list, entry);
        else
            list = create_node(entry);
    }
    my_sort_list(&list, (int (*)(void *, void *))cmp_dirent);
    return list;
}

void sub_folder(game_t *game, linked_list_t *list, sfVector2f pos)
{
    int col = 20;
    int space = 15;
    int tab = 120;
    int i = 0;
    struct dirent *file = get_file_from_pos(game, list, pos);

    for (linked_list_t *tmp = list; tmp; tmp = tmp->next, i += 20) {
        sfText_setColor(game->text, ((struct dirent *)tmp->data)->d_type == 4
        ? (sfColor) {96, 127, 255, 255} : sfWhite);
        add_text_at(game, game->text, ((struct dirent *)tmp->data)->d_name,
        (sfVector2f) {pos.x + (int)(i / (col * space)) *
        tab, pos.y + i % (col * space)});
        get_file_from_pos(game, list, pos) && !my_strcmp(((struct dirent *)
        tmp->data)->d_name, file->d_name) ? check_validation(game, file) : 0;
    }
}

void display_folder(game_t *game, char *path, sfVector2f pos)
{
    linked_list_t *list = get_folder(game, path);

    if (!list)
        return;
    sfText_setCharacterSize(game->text, 26);
    sfText_setStyle(game->text, sfTextItalic);
    sfText_setColor(game->text, sfWhite);
    sfText_setPosition(game->text, (sfVector2f){pos.x + 20, pos.y});
    sfText_setString(game->text, path);
    sfRenderWindow_drawText(game->window, game->text, NULL);

    sub_folder(game, list, pos);
    free_nodes(list);
    closedir(game->dir);
}
