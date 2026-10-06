/*
** EPITECH PROJECT, 2023
** loader.c
** File description:
** map loader
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

char *get_raw(char *path)
{
    FILE *file = fopen(path, "r");
    struct stat st;
    char *raw = NULL;

    if (file == NULL)
        return NULL;
    stat(path, &st);
    raw = malloc(sizeof(char) * st.st_size + 2);
    fread(raw, st.st_size, 1, file);
    raw[st.st_size + 1] = 0;
    raw[st.st_size] = '\n';
    fclose(file);
    return check_handling(raw) ? NULL : raw;
}

char *correct_end(char *raw, char c)
{
    char *tmp = my_strdup_up(raw, 1);

    tmp[my_strlen(raw)] = c;
    tmp[my_strlen(raw) + 1] = 0;

    free(raw);
    return tmp;
}

int get_next_int_pos(char *str, int *i)
{
    int n = 0;

    for (; !contain(str[*i], "0123456789") && str[*i]; (*i)++);
    for (; contain(str[*i], "0123456789") && str[*i]; (*i)++, n++);
    return n == my_strlen(str) ? -1 : n;
}

void sub_init_data(map_t *map, char **tmp, int i)
{
    char **split = NULL;
    for (int j = 0; tmp[j]; j++) {
        tmp[j] = correct_end(tmp[j], '-');
        split = my_str_to_array(tmp[j], "-");
        for (int n = 0, t = 0; n < 5; n++, t++)
            map->data[n][i][j] = n < my_arrlen(split) ?
            my_getnbr(split[t]) : 41;
    }
}

void init_data(map_t *map, char **raw)
{
    char **tmp = NULL;

    map->size.y = my_arrlen(raw);
    for (int i = 0; i < 5; i++)
        map->data[i] = malloc(sizeof(int *) * (map->size.y + 1));
    for (int i = 0; raw[i]; i++) {
        raw[i] = correct_end(raw[i], ',');
        tmp = my_str_to_array(raw[i], ",");
        map->size.x = my_arrlen(tmp);
        for (int n = 0; n < 5; n++)
            map->data[n][i] = malloc(sizeof(int) * (map->size.x + 1));
        sub_init_data(map, tmp, i);
    }
    free(tmp);
}
