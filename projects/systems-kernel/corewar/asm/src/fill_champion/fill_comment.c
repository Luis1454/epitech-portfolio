/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** fill_comment.c
*/

#include "asm_corewar.h"

void find_comment(char *str, header_t *header)
{
    int i = 0;
    int j = 0;

    for (; str[i] != '"'; i++);
    i++;
    for (; str[i] != '"' && str[i] != '\0'; i++, j++)
        header->comment[j] = str[i];
    header->comment[j] = '\0';
    return;
}

int fill_comment(header_t *header, char **array, char *line, int fd)
{
    find_comment(line, header);
    write(fd, &header->comment, COMMENT_LENGTH + 1);
    return 0;
}
