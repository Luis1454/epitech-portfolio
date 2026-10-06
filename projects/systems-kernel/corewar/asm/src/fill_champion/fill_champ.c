/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** fill_champ.c
*/

#include "asm_corewar.h"

char *my_memset_asm(char *str, char c, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = c;
    return str;
}

header_t init_header(header_t header)
{
    my_memset_asm(header.prog_name, 0, PROG_NAME_LENGTH + 1);
    my_memset_asm(header.comment, 0, COMMENT_LENGTH + 1);
    header.magic = revbytes(COREWAR_EXEC_MAGIC);
    header.prog_size = 0;
    return header;
}

int create_file(char *filepath)
{
    int fd = 0;
    int i = 0;
    char *buffer = malloc(sizeof(char) * my_strlen(filepath) + 3);

    for (; i < my_strlen(filepath); i++)
        buffer[i] = filepath[i];
    buffer[i - 1] = 'c';
    buffer[i] = 'o';
    buffer[i + 1] = 'r';
    fd = open(buffer, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    return fd;
}

void wich_categories(char *line, champion_t *champion, int fd)
{
    char **array_line = my_strtoword_array(line, ' ');
    static int head_comment = 0;
    header_t header;

    header = init_header(header);
    if (array_line == NULL)
        return;
    if (my_strncmp(array_line[0], NAME_CMD_STRING, 5) == 1) {
        fill_header(&header, array_line, line, fd);
        head_comment += 1;
        return;
    }
    if (my_strncmp(array_line[0], COMMENT_CMD_STRING, 8) == 1) {
        fill_comment(&header, array_line, line, fd);
        head_comment += 1;
        return;
    } else
        find_cmd(line, fd, champion);
}

int fill_champion(champion_t *champion, char *buffer, char *filepath)
{
    char **content = my_strtoword_array(buffer, '\n');
    int i = 0;
    int fd = 0;

    if (content_all(filepath, content) == 84)
        return 84;
    else
        fd = create_file(filepath);
    content = my_array_remove_char(content, '\t');
    for (; content[i] != NULL; i++) {
        wich_categories(content[i], champion, fd);
    }
    free(content);
    content = my_strtoword_array(buffer, '\n');
    write_command(fd, champion, content);
    return 0;
}
