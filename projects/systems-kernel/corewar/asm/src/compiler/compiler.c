/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** compiler.c
*/

#include "asm_corewar.h"

int read_file(int fd, champion_t *champion, char *filepath)
{
    char *buffer = malloc(sizeof(char) * (FILE_SIZE + 1));
    fd = open(filepath, O_RDONLY);
    int i = 0;

    read(fd, buffer, FILE_SIZE);
    return fill_champion(champion, buffer, filepath);
}

int test_file_path(char *filepath)
{
    int i = 0;

    for (; filepath[i] != '\0'; i++) {
        if (filepath[i] == '.' && filepath[i + 1] == 's')
            return (open_file(filepath));
    }
    return 84;
}

int compiler(char *filepath, champion_t *champion)
{
    int fd = 0;
    int i = 0;
    int return_value = 0;

    fd = test_file_path(filepath);
    if (fd == 84) {
        my_putstr_error("Error: File not found\n");
        return (84);
    }
    return_value = read_file(fd, champion, filepath);
    close(fd);
    return return_value;
}
