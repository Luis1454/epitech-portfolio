/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** main.c
*/

#include "asm_corewar.h"

void init_champion(champion_t *champion)
{
    champion->nb_champ = 0;
    champion->line_b_label = 0;
    champion->label_name = malloc(sizeof(char *) * 2048);
}

int main(int ac, char **av)
{
    int error_h = error_handler(ac, av);
    champion_t *champion = malloc(sizeof(champion_t));
    init_champion(champion);
    if (error_h == 84)
        return 84;
    if (error_h == 1)
        return 0;
    return compiler(av[1], champion);
}
