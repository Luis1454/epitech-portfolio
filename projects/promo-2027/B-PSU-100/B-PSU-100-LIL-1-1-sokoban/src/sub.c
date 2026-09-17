/*
** EPITECH PROJECT, 2022
** sub.c
** File description:
** sub functions
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/handling.h"

int load_map(Game *g, const char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat data;

    if (fd == -1)
        return 84;
    fstat(fd, &data);
    g->str = malloc(sizeof(char) * (data.st_size + 1));
    if (g->str == NULL)
        return close(fd) * 0 + 84;
    g->str[data.st_size] = 0;
    if (read(fd, g->str, data.st_size / sizeof(char)) == -1)
        return (sizeof(free(g->str)) || close(fd)) * 0 + 84;
    g->str = g->str[my_strlen(g->str) - 1] != '\n' ?
    my_strcat(g->str, "\n") : g->str;
    if (error_handling(g->str)) {
        free(g->str);
        return 84;
    }
    close(fd);
    return sub_load_map(g, data);
}

int sub_error(const char *str)
{
    if (get_nb('O', str) != get_nb('X', str)) {
        my_print_error("Error: number of boxes");
        my_print_error(" and storage locations differ\n");
        return 3;
    } else if (!only_contain("XO P#\n", str)) {
        my_print_error("Error: invalid character in map\n");
        return 4;
    }
    return 0;
}

int error_handling(const char *str)
{
    if (!get_nb('P', str)) {
        my_print_error("Error: no player found\n");
        return 1;
    } else if (get_nb('P', str) != 1) {
        my_print_error("Error: multiples players ");
        my_print_error("(1 expected,");
        my_print_nbr_error(get_nb('P', str));
        my_print_error(" found)\n");
        return 2;
    }
    return sub_error(str);
}

int init_game(char const *argv[])
{
    int state = 0;
    Game *g = malloc(sizeof(Game));

    if (g == NULL) {
        free(g);
        return 84;
    }
    state = load_map(g, argv[1]);
    free(g);
    return state;
}
