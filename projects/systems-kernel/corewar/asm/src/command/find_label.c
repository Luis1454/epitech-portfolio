/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** find_label.c
*/

#include "asm_corewar.h"

int find_label_w(char *command)
{
    int i = 0;
    int distance = 0;

    command = my_c_clean_str(command, '%');
    command = my_c_clean_str(command, ':');
    for (; i < champ->nb_champ; i++) {
        if (my_strncmp(command, champ->label_name[i][0], my_strlen(command))
        == 1 && my_strlen(command) == my_strlen(champ->label_name[i][0])) {
            distance = champ->label_name[i][1];
            return distance;
        }
    }
    return 0;
}

int there_is_label(char **command)
{
    int i = 0;

    for (i = 0; command[i] != NULL; i++) {
        if (command[i][0] == LABEL_CHAR)
            find_label_w(command[i]);
    }
    return 0;
}
