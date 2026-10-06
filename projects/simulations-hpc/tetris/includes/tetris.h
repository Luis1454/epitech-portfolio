/*
** EPITECH PROJECT, 2021
** tetris.h
** File description:
** custom includes
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <getopt.h>
    #include <ncurses.h>
    #include "my.h"

    #define BLOCK 'O'
    #define KEY_Q 'q'
    #define KEY_SPACE ' '
    #define SHORTOPT "L:l:r:t:d:q:p:wD"

typedef struct cell {
    int color;
    int state;
} Cell;

typedef struct vect2d
{
    int x;
    int y;
} Vect2d;

typedef struct piece {
    char *name;
    int color;
    Vect2d size;
    int **shape;
} Piece;

typedef struct options {
    int level;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int map_size[2];
    bool hide;
    bool debug;
} Options;

typedef struct game {
    Options *opt;
    Cell **unit;
    Piece preview;
    Piece *pieces;
    int is_fake[1000];
    int nb_pieces;
    int current_score;
    int high_score;
    int completed_lines;
    int level;
    int timer;
    char *buffer;
    int i;
} Game;

void init(Game *g);

int get_piece(Game *g, char *raw);

Options *init_options(void);

void get_options(int ac, char **av, Options *opt);

void choose_params(Options *opt, char ch, int *i);

void print_options(Options *opt);

void nprint(int A, char *str, int B);

void print(char *A, int n, char *B);

void strprint(char *A, char *str, char *B);

void print_block(int *shape_i, int len, int j);

void print_map(Game *g, int n);

#endif /* INCLUDE_H_ */
