/*
** EPITECH PROJECT, 2022
** librairie cmpt
** File description:
** init_open_file.c
*/

#include "my.h"

int file_size(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return 0;
    char *buffer = malloc(sizeof(char) * 100000);
    int file_size = read(fd, buffer, 100000);
    close(fd);
    free(buffer);
    return (file_size);
}

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *buffer = malloc(sizeof(char) * (size_file(file) + 1));
    int size = read(fd, buffer, size_file(file));
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
