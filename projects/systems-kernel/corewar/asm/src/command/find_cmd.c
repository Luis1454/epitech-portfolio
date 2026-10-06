/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** find_cmd.c
*/

#include "asm_corewar.h"

champion_t *champ;

command_finder_t const command_finder[16] =
{
    {"live", live, 1},
    {"ld", ld_c, 2},
    {"st", st_c, 2},
    {"add", add, 2},
    {"sub", sub, 2},
    {"and", and_c, 2},
    {"or", or_c, 2},
    {"xor", xor_c, 2},
    {"zjmp", zjmp, 1},
    {"ldi", ldi, 2},
    {"sti", sti, 2},
    {"fork", fork_a, 1},
    {"lld", lld, 2},
    {"lldi", lldi, 2},
    {"lfork", lfork, 1},
    {"aff", aff, 2}
};

char *select_command(char *command, champion_t *champion, int fd)
{
    char **array_command = my_strtoword_array(command, ' ');
    int i = 0;
    char *precedent_cmd = NULL;

    if (array_command == NULL)
        return NULL;
    if (array_command[0] == NULL || array_command[1] == NULL)
        return NULL;
    for (; i < 16; i++) {
        if (my_strncmp(array_command[0], command_finder[i].command,
        my_strlen(array_command[0])) == 1 && my_strlen(array_command[0]) ==
        my_strlen(command_finder[i].command)) {
            command_finder[i].function(array_command, fd);
        }
    }
    return NULL;
}

int find_label(char *line, champion_t *champion)
{
    int i = 0;
    char **array = my_strtoword_array(line, ':');

    for (; line[i] != '\0'; i++) {
        if (line[i] == LABEL_CHAR && line[i - 1] != '\0' && line[i - 1] !=
        '%') {
            champion->label_name[champion->nb_champ] = malloc(sizeof(char) * 3);
            champion->label_name[champion->nb_champ][0] = malloc(sizeof(char) *
            my_strlen(line));
            champion->label_name[champion->nb_champ][0] = my_strdup(array[0]);
            champion->label_name[champion->nb_champ][1] =
            champion->line_b_label;
            champion->label_name[champion->nb_champ][2] = '\0';
            champion->nb_champ += 1;
            return 1;
        }
    }
    return 0;
}

char *add_type(char *command, champion_t *champion, char *p_command)
{
    int i = 0;

    for (; command[i] != '\0'; i++) {
        if (command[i] == DIRECT_CHAR) {
            champion->line_b_label += (my_strcmp(p_command, "ld") == 0) ? 2 : 4;
            return NULL;
        }
        if (command[i] == 'r') {
            champion->line_b_label += 1;
            return NULL;
        }
        champion->line_b_label += 4;
    }
    return NULL;
}

char *add_bytes(char *command, champion_t *champion, char *p_command)
{
    for (int i = 0; i < 16; i++) {
        if (my_strncmp(command, command_finder[i].command,
        my_strlen(command)) == 1 && my_strlen(command) == my_strlen(
        command_finder[i].command)) {
            champion->line_b_label += command_finder[i].value;
            return command_finder[i].command;
        }
    }
    return add_type(command, champion, p_command);
}

int find_cmd(char *line, int fd, champion_t *champion)
{
    char **array = NULL;
    char **command = my_strtoword_array(line, ' ');
    char *precedent_cmd = NULL;
    command = my_array_remove_char(command, ',');
    int i = 0;

    for (; command[i] != NULL; i++) {
        if (find_label(command[i], champion) == 0) {
            precedent_cmd = add_bytes(command[i], champion, precedent_cmd);
        }
    }
    champ = champion;
    return 0;
}
