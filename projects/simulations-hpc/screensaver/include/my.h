/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my of h files
*/

#ifndef _MY_H
    #define _MY_H

int get_particule(int v);

int **get_particles_field(int Xsize, int Ysize, int nb);

int ***get_particles_vect_field(int Xsize, int Ysize);

int **make_move(int **field, int ***vect_field, int Xsize, int Ysize);

int make_life(int **map, int x, int y, int Xsize);

int make_life_2(int **map, int x, int y, int Xsize);

sfColor get_rgb(sfUint8 r, sfUint8 g, sfUint8 b);

sfColor *gravity(sfColor *pixels, int **field, int Xsize, int Ysize);

sfColor *rd_pixel(sfColor *pixels, int Xsize, int Ysize, int t);

sfColor *noise(sfColor *pixels, int Xsize, int Ysize, int t);

sfColor *netflix(sfColor *pixels, int Xsize, int Ysize, int t);

sfColor *rain(sfColor *pixels, int Xsize, int Ysize);

sfColor *life_game(sfColor *pixels, int **field, int Xsize, int Ysize);

#endif /* _MY_H */
