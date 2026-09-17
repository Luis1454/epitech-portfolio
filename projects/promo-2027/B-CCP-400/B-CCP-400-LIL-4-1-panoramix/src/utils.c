/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils functions
*/

#include "../include/panoramix.h"

void safe_free(void *ptr)
{
    if (ptr)
        free(ptr);
    ptr = NULL;
}

int parser(panoramix_t *p, int argc, char **argv)
{
    if (argc != 5) {
        printf("USAGE: %s <nb_villagers> <pot_size> " \
        "<nb_fights> <nb_refills>\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < 5; i++)
        if (atoi(argv[i]) <= 0)
            return 1;
    p->nb_villagers = atoi(argv[1]);
    p->pot_size = atoi(argv[2]);
    p->nb_fights = atoi(argv[3]);
    p->nb_refills = atoi(argv[4]);
    return 0;
}
