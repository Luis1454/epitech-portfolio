/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** find_cmd.c
*/

#include "lib.h"

command_finder_t const command_finder[16] =
{
    {"live", live},
    {"ld", ld_c},
    {"st", st_c},
    {"add", add},
    {"sub", sub},
    {"and", and_c},
    {"or", or_c},
    {"xor", xor_c},
    {"zjmp", zjmp},
    {"ldi", ldi},
    {"sti", sti},
    {"fork", fork_a},
    {"lld", lld},
    {"lldi", lldi},
    {"lfork", lfork},
    {"aff", aff}
};

int find_cmd_corewar(char *buffer, int fd)
{
    for (int i = 0; i < 16; i++) {
        if (my_strncmp(buffer, command_finder[i].command,
        my_strlen(command_finder[i].command)) == 0) {
            my_printf("command: %s\n", buffer);
            command_finder[i].function(buffer, fd);
            return 0;
        }
    }
    return 0;
}
