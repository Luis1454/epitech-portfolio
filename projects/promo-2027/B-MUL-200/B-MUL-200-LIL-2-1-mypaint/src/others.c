/*
** EPITECH PROJECT, 2023
** others.c
** File description:
** others functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"
#include <dirent.h>
#include <sys/types.h>

linked_list_t *get_folder(screen_t *s, char *path)
{
    struct dirent *entry;
    linked_list_t *list = NULL;
    int i = 0;

    if (!(s->dir = opendir(path)))
        return NULL;
    for (; (entry = readdir(s->dir)) != NULL; i++) {
        if (i)
            append_node(&list, entry);
        else
            list = create_node(entry);
    }
    my_sort_list(&list, (int (*)(void *, void *))cmp_dirent);
    return list;
}

void sub_folder(screen_t *s, linked_list_t *list, sfVector2f pos)
{
    int col = 15;
    int space = 20;
    int tab = 120;
    int i = 0;
    struct dirent *file = get_file_from_pos(s, list, pos);

    for (linked_list_t *tmp = list; tmp; tmp = tmp->next, i += 20) {
        display_text(s,
        ((struct dirent *)tmp->data)->d_name,
        (sfVector2f) {pos.x + (int)(i / (col * space)) *
        tab, pos.y + i % (col * space) + space * 2},
        mix_color(((struct dirent *)tmp->data)->d_type == 4
        ? sfBlue : sfBlack, sfWhite,
        get_file_from_pos(s, list, pos) && !my_strcmp(((struct dirent *)
        tmp->data)->d_name, file->d_name) ? check_validation(s, file) : 0));
    }
}

void display_folder(screen_t *s, char *path, sfVector2f pos)
{
    linked_list_t *list = get_folder(s, path);

    if (!list)
        return;
    sfText_setCharacterSize(s->text, 18);
    sfText_setStyle(s->text, sfTextItalic);
    sfText_setColor(s->text, sfBlack);
    sfText_setPosition(s->text, (sfVector2f){pos.x + 20, pos.y});
    sfText_setString(s->text, path);
    sfRenderWindow_drawText(s->window, s->text, NULL);

    sub_folder(s, list, pos);
    free_nodes(list);
    closedir(s->dir);
}

void sub_panel_handler(screen_t *s, button_t *b)
{
    if ((b = get_button_by_name(s->toolbar, "Pencil"))->state) {
        s->current_brush = get_brush_by_id(s, 1);
        b->state = 0;
    }
    if ((b = get_button_by_name(s->toolbar, "Eraser"))->state) {
        s->current_brush = get_brush_by_id(s, 0);
        b->state = 0;
    }
    if ((b = get_button_by_name(s->toolbar, "Help"))->child->child->state) {
        help_panel(s);
        b->state = 0;
    }
    if ((b = get_button_by_name(s->toolbar, "Help"))->child->state) {
        about_panel(s);
        b->state = 0;
    }
}

void panel_handler(screen_t *s)
{
    button_t *b;

    if ((b = get_button_by_name(s->toolbar, "Open"))->state
    && !get_button_by_name(s->toolbar, "Save")->state)
        display_open_panel(s, (sfVector2f){s->size.x / 2, s->size.y / 2});
    if ((b = get_button_by_name(s->toolbar, "Save"))->state)
        display_save_panel(s, b, 1);
    if ((b = get_button_by_name(s->toolbar, "New"))->state) {
        destroy_image(s->image);
        create_new(s, (sfVector2i){800, 600}, NULL);
        b->state = 0;
    }
    if ((b = get_button_by_name(s->toolbar, "Exit"))->state) {
        s->state = 0;
        b->state = 0;
    }
    sub_panel_handler(s, b);
}
