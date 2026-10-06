/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** sokoban library
*/

#include <ncurses.h>

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    typedef struct vector_2i {
        int x;
        int y;
    } Vect_2i;

    typedef struct game {
        Vect_2i default_pos;
        Vect_2i size;
        Vect_2i max;
        Vect_2i pos;
        char **map;
        char *str;
        int state;
        int nb_o;
        int nb_x;
        int key;
    } Game;

int is_locked(Game *g, Vect_2i v);

int all_box_locked(Game *g);

int all_box_placed(Game *g);

void mv_box(Game *g, Vect_2i v, int x, int y);

int check_box(Game *g, Vect_2i v, int x, int y);

void format_map(Game *g);

void get_move(Game *g);

void display_map(Game *g);

void reset_map(Game *g);

int display_usage(void);

int load_map(Game *g, const char *path);

int error_handling(const char *str);

int init_game(char const *argv[]);

int sub_loop(Game *g);

int game_loop(Game *g);

int start_game(Game *g, char *str, struct stat data);

int sub_load_map(Game *g, struct stat data);

int main(int argc, char const *argv[]);

int get_size_x(const char *str);

int get_size_y(const char *str);

int free_map(char **map, int size);

int get_nb(const char c, const char *str);

#endif /* SOKOBAN_H_ */
