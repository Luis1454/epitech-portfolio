/*
** EPITECH PROJECT, 2023
** panel.c
** File description:
** panel functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/mylist.h"
#include "../include/my_macro_abs.h"
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

char *sub_resolve(char **path, int i)
{
    int j = 0;

    for (j = i - 1; j >= 0; j--)
        if (path[j]) {
            free(path[j]);
            path[j] = NULL;
            break;
        }
    free(path[i]);
    path[i] = NULL;
    return NULL;
}

void resolve_path(screen_t *s)
{
    char **path = my_str_to_array(s->path, "/");
    int i = 0;

    for (; path[i]; i++)
        if (!my_strcmp(path[i], ".."))
            path[i] = sub_resolve(path, i);
    s->path = malloc(sizeof(char) * 2048);
    s->path = my_memset(s->path, 0, 2048);
    s->path = my_strcpy(s->path, "/");
    for (i = 0; path[i]; i++) {
        if (i)
            s->path = my_strcat(s->path, "/");
        s->path = my_strcat(s->path, path[i]);
    }
    free_array(path);
}

void slider_handler(screen_t *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (is_in_slider(s, s->current_brush->opacity))
            set_slider_value(s->current_brush->opacity,
            get_value_from_pos(s->current_brush->opacity, s->mouse_pos));
        if (is_in_slider(s, s->current_brush->size))
            set_slider_value(s->current_brush->size,
            get_value_from_pos(s->current_brush->size, s->mouse_pos));
        if (is_in_slider(s, s->current_brush->smooth))
            set_slider_value(s->current_brush->smooth,
            get_value_from_pos(s->current_brush->smooth, s->mouse_pos));
    }
}
