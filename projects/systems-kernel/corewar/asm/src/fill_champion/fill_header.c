/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** fill_header.c
*/

#include "asm_corewar.h"

int rev_2_bit(int bytes)
{
    int rev = 0;

    rev = (bytes & 0xFF) << 8 | (bytes & 0xFF00) >> 8;
    return rev;
}

int revbytes(int value)
{
    return (value & 0xFF) << 24 | (value & 0xFF00) << 8 | (value & 0xFF0000) >>
    8 | (value & 0xFF000000) >> 24;
}

void find_name(char *str, header_t *header)
{
    int i = 0;
    int j = 0;

    for (; str[i] != '"'; i++);
    i++;
    for (; str[i] != '"' && str[i] != '\0'; i++, j++)
        header->prog_name[j] = str[i];
    header->prog_name[j] = '\0';
    return;
}

int fill_header(header_t *header, char **array, char *line, int fd)
{
    int magic = revbytes(COREWAR_EXEC_MAGIC);
    write(fd, &magic, sizeof(int));
    find_name(line, header);
    write(fd, header->prog_name, PROG_NAME_LENGTH + 8);
    return 0;
}
