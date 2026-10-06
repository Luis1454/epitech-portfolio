/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** .h file for lemin
*/

#include "libmy.h"

#ifndef LEMIN_H_
    #define LEMIN_H_

    typedef struct tunnel {
        struct tunnel *next;
        struct room *dest;
    } tunnel_t;

    typedef struct pipe {
        char *in;
        char *out;
        struct pipe *next;
    } pipe_t;

    typedef struct room {
        char *name;
        int id;
        int is_end;
        int is_visited;
        int is_occupied;
        unsigned int x;
        unsigned int y;
        unsigned int nb_ants;
        struct tunnel *tunnels;
        struct room *next;
    } room_t;

    typedef struct ant {
        int id;
        room_t *room;
    } ant_t;

    typedef struct path {
        room_t *room;
        struct path *next;
    } path_t;

    typedef struct anthill {
        unsigned int nb_rooms;
        unsigned int nb_tunnels;
        unsigned int nb_ants;
        unsigned int start_id;
        unsigned int end_id;
        room_t *rooms;
        path_t *path;
        ant_t *ants;
        pipe_t *p;
    } anthill_t;

void display_datas(anthill_t *hill);

void check_splits(anthill_t *hill, char *line);

void store_pipe(anthill_t *hill, char *a, char *b);

char *my_strndupp(char *str, int nb);

char *read_file(void);

char *clean_str(char *str);

char **remove_comment(char **all_info);

char **verif_start_and_end(char **all_info);

char **recup_file(void);

char **error(char **all_info, int i);

char **clean_tab(char **all_info);

char **verif_same_room(char **all_info);

int my_str_numb(char *str, char c);

int count_space(char *str);

int count_number(char *str);

int init_tab(char **raw);

int start_by(char *str, char *start);

int game_loop(anthill_t *hill);

int append_room(anthill_t *hill, char *name, int x, int y);

int count_line(char **all_info);

int all_args_are_digits(char **arr);

int append_tunnel(room_t *room, room_t *dest);

int append_path(path_t **path, path_t *new);

int init_tab(char **raw);

int init_rooms(anthill_t *hill, char **raw);

path_t *get_path_by_id(path_t *paths, int id);

room_t *get_room_by_name(anthill_t *hill, char *name);

room_t *get_room_by_id(anthill_t *hill, int id);

path_t *find_path(anthill_t *hill, room_t *start, room_t *end, path_t *path);

ant_t *get_ant_by_room(anthill_t *hill, room_t *room);

tunnel_t *get_tunnel_by_id(tunnel_t *tunnels, int id);

#endif /* !LEMIN_H_ */
