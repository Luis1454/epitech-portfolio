/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** laod_map.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

int load_map(char *path, map_t *map)
{
    char *raw = get_raw(path);
    char **tmp = NULL;

    if (raw == NULL)
        return 1;
    tmp = my_str_to_array(raw, "\n");
    map->data = malloc(sizeof(int **) * 5);
    init_data(map, tmp);
    free(raw);
    return 0;
}
