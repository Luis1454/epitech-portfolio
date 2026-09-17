/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int sub_loop(Game *g)
{
    getmaxyx(stdscr, g->max.x, g->max.y);
    g->key == 32 ? reset_map(g) : 0;
    if (all_box_locked(g) || g->key == 27) {
        refresh();
        return (g->key != 27) + 1;
    }
    if (g->max.x >= g->size.x && g->max.y >= g->size.y) {
        display_map(g);
        g->key = getch();
        get_move(g);
    } else {
        printw("Screen too small on %c axis\n",
        g->max.x < g->size.x ? 'x' : 'y');
    }
    refresh();
    clear();
    return 0;
}

int game_loop(Game *g)
{
    int state = 0;

    while (!all_box_placed(g) && !(state = sub_loop(g)));
    endwin();
    return state == 2;
}

int start_game(Game *g, char *str, struct stat data)
{
    int i = find_out(str, 'P');

    for (int j = 0; j < data.st_size; j++)
        g->str[j] = str[j];
    g->nb_o = get_nb('O', str);
    g->nb_x = get_nb('X', str);
    g->pos = (Vect_2i){i % (g->size.x + 1), i / (g->size.x + 1)};
    g->default_pos = g->pos;
    g->map[g->pos.y][g->pos.x] = ' ';
    g->str[i] = ' ';
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    return game_loop(g);
}

int sub_load_map(Game *g, struct stat data)
{
    g->size = (Vect_2i){get_size_x(g->str), get_size_y(g->str) + 1};
    g->map = malloc(sizeof(char *) * g->size.y / sizeof(char));
    g->map == NULL ? free(g->str) : 0;
    if (g->map == NULL)
        return 84;
    for (int i = 0; i < g->size.y; i++) {
        g->map[i] = malloc(sizeof(char) * (g->size.x + 1));
        g->map[i] == NULL ? free(g->str) : 0;
        if (g->map[i] == NULL)
            return free_map(g->map, g->size.y / sizeof(char)) + 84;
    }
    format_map(g);
    for (int i = 0; g->str[i]; i++)
        g->map[i / (g->size.x + 1)][i % (g->size.x + 1)] = g->str[i];
    if (!(g->state = !(find_out(g->str, 'P') >= 0)))
        g->state = start_game(g, g->str, data);
    free(g->str);
    free_map(g->map, g->size.y / sizeof(char));
    return g->state;
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        my_print_error("Invalid number of arguments (");
        argc > 2 ? my_print_nbr_error(argc - 1) : 0;
        my_print_error(argc > 2 ? " arguments found but only 1 expected)\n" :
        "no argument found, 1 expected)\n");
        return 84;
    }
    if (!my_strcmp(argv[1], "-h") || !my_strcmp(argv[1], "--help"))
        return display_usage();
    return init_game(argv);
}
