/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** open_file.c
*/

#include "asm_corewar.h"

int open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return 84;
    }
    return fd;
}
