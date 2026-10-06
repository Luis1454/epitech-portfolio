/*
** EPITECH PROJECT, 2022
** assert_a.c
** File description:
** assertion functions
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"
#include "../../include/mylist.h"
#include "../../include/handling.h"
#include "../../include/my_macro_abs.h"

void free_map(map_t *map)
{
    if (!map)
        return;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < map->size.y; j++)
            map->data[i][j] ? free(map->data[i][j]) : 0;
        map->data[i] ? free(map->data[i]) : 0;
    }
    map->data ? free(map->data) : 0;
    sfSprite_destroy(map->sprite);
    free(map);
}

int check_extension(char *str, char *ext)
{
    int len = my_strlen(str);
    int ext_len = my_strlen(ext);

    if (len < ext_len)
        return 0;
    return !my_strcmp(&str[len - ext_len], ext);
}

void sub_validation(game_t *g, struct dirent *file)
{
    if (file->d_type != 4 && (check_extension(file->d_name, ".txt")
    || check_extension(file->d_name, ".TXT"))) {
        if (g->file)
            free(g->file);
        g->file = malloc(sizeof(char) * 2048);
        g->file = my_memset(g->file, 0, 2048);
        g->file = my_strcpy(g->file, g->path);
        g->file = my_strcat(g->file, "/");
        g->file = my_strcat(g->file, file->d_name);
        if (g->map)
            free_map(g->map);
        g->map = malloc(sizeof(map_t));
        load_map(g->file, g->map);
        g->map->sprite = sfSprite_create();
        sfSprite_setTexture(g->map->sprite, g->texture->iso, sfTrue);
        g->map->zoom_speed = 0.1;
        g->map->rescale = 1;
        g->player->pos = (sfVector2f){g->map->size.x / 2, g->map->size.y / 2};
        g->menu_id = get_id_by_menu_name(g->menu, "New game");
    }
}

double check_validation(game_t *g, struct dirent *file)
{
    int len = my_strlen(file->d_name) + 2;

    if (sfMouse_isButtonPressed(sfMouseLeft)
    && g->last) {
        if (file && file->d_type == 4) {
            len += my_strlen(g->path);
            g->path = my_strcat(g->path, "/");
            g->path = my_strcat(g->path, file->d_name);
            resolve_path(g);
        }
        sub_validation(g, file);
        sfRenderWindow_setTitle(g->window, g->file);
    }
    g->last = g->event.type == sfEvtMouseButtonReleased;
    return 0.35;
}

struct dirent *get_file_from_pos(game_t *g, linked_list_t *l, sfVector2f pos)
{
    int col = 15;
    int space = 20;
    int tab = 120;
    int index = 0;
    int len = my_list_size(l);
    linked_list_t *tmp = l;
    sfVector2i pos_in_grid = (sfVector2i){(g->mouse_pos.x
    - pos.x) / tab, (g->mouse_pos.y - pos.y - 20) / space};

    index = pos_in_grid.x * col + pos_in_grid.y;
    if (index >= 0 && index < len && pos_in_grid.x >= 0
    && pos_in_grid.y >= 0 && pos_in_grid.x <= len / col
    && pos_in_grid.y < col) {
        for (tmp = l; tmp && index--; tmp = tmp->next);
        if (tmp)
            return (struct dirent *)tmp->data;
    }
    return NULL;
}
