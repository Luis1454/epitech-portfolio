/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** winner_loop.c
*/

#include "lib.h"

void end_game(prog_t *prog)
{
    if (prog->last_alive == NULL) {
        my_putstr("No winner\n");
        return;
    }
}
