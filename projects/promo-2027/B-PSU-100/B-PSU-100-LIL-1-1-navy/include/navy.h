/*
** EPITECH PROJECT, 2022
** navy.h
** File description:
** navy library
*/

#include <ncurses.h>

#ifndef NAVY_H_
    #define NAVY_H_

    typedef struct vector_2i {
        int x;
        int y;
    } Vect_2i, vect_2i;

    typedef struct boat {
        Vect_2i start;
        Vect_2i end;
        int size;
    } Boat;


    vect_2i get_vect_from_str(char *str);

    int get_map(char **map, char *filepath);

    vect_2i receve_binary_pos(void);

    void signal_handler(int sig, siginfo_t *siginfo, void *context);

#endif /* NAVY_H_ */
