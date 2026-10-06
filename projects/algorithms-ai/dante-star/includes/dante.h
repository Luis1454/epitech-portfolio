/*
** EPITECH PROJECT, 2022
** dante.h
** File description:
** struct dante
*/

#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef DANTE_H_
    #define DANTE_H_

typedef struct data_s {

    int x;
    int y;
    char **map;
    char **mask;
    char **check;
    char *perfect;

}data_t;

typedef struct solver_s {
    char **map;
    char *path;
    int i;
    int len;
    int line;
    int count;
    int x;
    int y;
    int pos_x;
    int pos_y;
    int sav_x;
    int sav_y;
}solver_t;

void corner(solver_t *m, int len, int line);
int line_len(char *buffer);
int nbr_line(char *buffer);
int check(int fd, int size);
char **map_2darr(char const *filepath);
int nbr_l(char **map);
void fill(char *buffer, char *map);
char **fill_map(char *buffer);
int nbr(char *str);
void core_block(solver_t *m, int len, int line);
void sub_core_block(solver_t *m, int len);
void up(solver_t *m);
void left(solver_t *m);
void down(solver_t *m, int line);
void right(solver_t *m, int len);
int end(solver_t *m, int len, int line);
int direction_dead(solver_t *m, int len, int line);
void upd(solver_t *m);
void leftd(solver_t *m);
void rightd(solver_t *m, int len);
void downd(solver_t *m, int line);
int cross(solver_t *m);
int redirection(solver_t *m, int len, int line);
int row(solver_t *m);
int check_reset(solver_t *m);
int sub_cross(solver_t *m);

#endif /* DANTE_H_ */
