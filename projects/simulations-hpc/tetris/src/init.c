/*
** EPITECH PROJECT, 2022
** init.h
** File description:
** init file
*/

#include "../includes/tetris.h"
#include "../includes/my.h"

void init(Game *g)
{
    g->opt = malloc(sizeof(Options));
    g->i = 0;
    g->nb_pieces = 0;
    g->buffer = malloc(sizeof(char) * 100);
    g->pieces = malloc(sizeof(Piece) * 10000);
}
