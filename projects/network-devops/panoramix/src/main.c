/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** panoramix main
*/

#include "../include/panoramix.h"

int main(int argc, char **argv)
{
    panoramix_t p;

    if (parser(&p, argc, argv) == 1)
        return 84;
    p.villagers = malloc(sizeof(villager_t) * p.nb_villagers);
    if (p.villagers == NULL)
        return 84;
    if (init_druid(p)) {
        safe_free(p.villagers);
        return 84;
    }
    safe_free(p.villagers);
    return 0;
}
