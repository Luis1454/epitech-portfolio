/*
** EPITECH PROJECT, 2023
** panel.c
** File description:
** panel functions
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"
#include "../../include/handling.h"
#include "../../include/mylist.h"
#include "../../include/my_macro_abs.h"
#include <dirent.h>
#include <sys/types.h>

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

void resolve_path(game_t *g)
{
    char **path = my_strtok(g->path, "/");
    int i = 0;

    for (; path[i]; i++) {
        if (!my_strcmp(path[i], ".."))
            path[i] = sub_resolve(path, i);
    }
    g->path = malloc(sizeof(char) * 2048);
    g->path = my_memset(g->path, 0, 2048);
    g->path = my_strcpy(g->path, "/");
    for (i = 0; path[i]; i++) {
        if (i)
            g->path = my_strcat(g->path, "/");
        g->path = my_strcat(g->path, path[i]);
    }
    free_array(path);
}
