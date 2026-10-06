/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** write_command.c
*/

#include "asm_corewar.h"

idx_w_value_t idx_value[16] =
{
    {0x01, 1},
    {0x02, 2},
    {0x03, 2},
    {0x04, 3},
    {0x05, 3},
    {0x06, 3},
    {0x07, 3},
    {0x08, 3},
    {0x09, 1},
    {0x0a, 3},
    {0x0b, 3},
    {0x0c, 1},
    {0x0d, 2},
    {0x0e, 3},
    {0x0f, 1},
    {0x10, 1}
};

void label_command(char *line, champion_t *champion, int fd, char *p_cmd)
{
    char **array_command = NULL;
    int size = 0;
    int i = 0;

    array_command = my_strtoword_array(line, ':');
    size = my_array_size(array_command);
    if (size == 2)
        array_command[1] = my_clean_str(array_command[1]);
    if (size == 2) {
        select_command(array_command[1], champion, fd);
    } else
        return;
}

void write_command(int fd, champion_t *champion, char **content)
{
    int i = 0;
    content = my_array_remove_char(content, ',');
    char *precedent_cmd = NULL;

    for (; content[i] != NULL; i++) {
        content[i] = replace_char(content[i], '\t', ' ');
        content[i] = my_clean_str(content[i]);
        if (find_label(content[i], champion) == 0) {
            precedent_cmd = select_command(content[i], champion, fd);
        } else {
            label_command(content[i], champion, fd, precedent_cmd);
        }
    }
    return;
}
