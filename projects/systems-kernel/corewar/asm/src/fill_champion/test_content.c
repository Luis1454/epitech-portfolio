/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** test_content.c
*/

#include "asm_corewar.h"

int name_all(char **line, int i)
{
    int array_size = my_array_size(line);
    line = my_strtoword_array(line[i], '"');
    if (line[1] == NULL)
        return 0;
    if (my_strlen(line[1]) > PROG_NAME_LENGTH)
        return 0;
    return 1;
}

int comment_all(char **line, int i)
{
    int array_size = my_array_size(line);
    line = my_strtoword_array(line[i], '"');
    if (line[1] == NULL)
        return 0;
    if (my_strlen(line[1]) > COMMENT_LENGTH)
        return 0;
    return 1;
}

int content_all(char *filepath, char **content)
{
    char **line = NULL;
    int name = 0;
    int com = 0;
    int i = 0;

    content = my_array_remove_char(content, '\t');
    for (; content[i] != NULL; i++) {
        line = my_strtoword_array(content[i], ' ');
        if (my_strncmp(line[0], NAME_CMD_STRING, 5) == 1)
            name += name_all(content, i);
        if (my_strncmp(line[0], COMMENT_CMD_STRING, 8) == 1)
            com += comment_all(content, i);
    }
    if (name != 1 || com != 1)
        return 84;
    return 0;
}
