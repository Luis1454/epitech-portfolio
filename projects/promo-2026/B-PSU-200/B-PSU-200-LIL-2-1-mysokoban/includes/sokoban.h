/*
** EPITECH PROJECT, 2021
** include.h
** File description:
** custom graphical include
*/

#include <ncurses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct player
{
    int X;
    int Y;
} Player;

typedef struct map
{
    char **datas;
    char **base;
    int Xsize;
    int Ysize;
    int key;
    Player player;
} Map;

int check_free_space(Map *map, int i, int j);

int sub_is_movable(Map *map, int i);

int sub_still_rewards(Map *map, int i);

void sub_check_map(Map *map, int i, int j);

int sub_main();

int get_nb_char(Map map, char c);

int is_movable(Map *map);

int is_free(Map *map, int x, int y);

int still_rewards(Map *map);

void check_map(Map *map);

void print_map(Map *map);

void get_key(Map *map);

void place_player(Map map);

char **get_map(char *str);

#endif /* INCLUDE_H_ */
