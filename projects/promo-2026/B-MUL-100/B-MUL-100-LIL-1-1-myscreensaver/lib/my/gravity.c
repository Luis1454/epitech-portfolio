/*
** EPITECH PROJECT, 2021
** life_game.c
** File description:
** gravity functions
*/

#include <stdlib.h>

#include "../../include/include.h"
#include "../../include/my.h"

int get_particule(int v)
{
    if (!(rand() % v))
        return 1;
    return 0;
}

int ***get_particles_vect_field(int Xsize, int Ysize)
{
    int s = 1;
    int ***field = malloc(sizeof(int **) * Xsize);

    for (int i = 0; i < Xsize; i++)
        field[i] = malloc(sizeof(int *) * Ysize);

    for (int i = 0; i < Xsize; i++)
        for (int j = 0; j < Ysize; j++)
            field[i][j] = malloc(sizeof(int) * 2);

    for (int i = 0; i < Xsize; i++)
        for (int j = 0; j < Ysize; j++){
            field[i][j][0] = rand() % s - s / 2;
            field[i][j][1] = rand() % s - s / 2;
        }
    return field;
}

int **get_particles_field(int Xsize, int Ysize, int nb)
{
    int **field = malloc(sizeof(int *) * Xsize);

    for (int i = 0; i < Xsize; i++)
        field[i] = malloc(sizeof(int) * Ysize);

    for (int i = 0; i < Xsize; i++)
        for (int j = 0; j < Ysize; j++)
            field[i][j] = get_particule(nb);
    return field;
}

sfColor *gravity(sfColor *pixels, int **field, int Xsize, int Ysize)
{
    for (int i = 0; i < Xsize; i++)
        for (int j = 0; j < Ysize; j++)
            pixels[i * Ysize + j] =
            get_rgb(field[i][j]*255, field[i][j]*255, field[i][j]*255);
}

int **make_move(int **field, int ***vect_field, int Xsize, int Ysize)
{
    int x;
    int y;

    for (int i = 0; i < Xsize; i++)
        for (int j = 0; j < Ysize; j++) {
            x = i + vect_field[i][j][0];
            y = j + vect_field[i][j][1];
            field[x][y] = field[i][j] ? 1 : field[x][y];
        }
}
