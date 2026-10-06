/*
** EPITECH PROJECT, 2023
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** parser.c
*/

#include "../include/parser.h"

int parser(int ac, char **av)
{
    Elf64_Ehdr header;
    int fd = open(av[1], O_RDONLY);

    if (ac == 2 && (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0))
        return display_help();
    if (access(av[1], X_OK) == -1) {
        fprintf(stderr, "Error: Cannot access or execute file %s\n", av[1]);
        return (84);
    }
    if (fd == -1) {
        perror("Error opening file");
        return 84;
    }
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: Unable to read ELF header\n");
        close(fd);
        return 84;
    }
    return (0);
}
