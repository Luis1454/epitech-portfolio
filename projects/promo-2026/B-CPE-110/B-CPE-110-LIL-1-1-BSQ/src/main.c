/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main src file
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my.h"

void sub_get_map(char **map, int nb_lines, int len_lines)
{
    int **mask = malloc(sizeof(int *) * (nb_lines + 1));

    for (int i = 0; i < nb_lines + 1; i++)
        mask[i] = malloc(sizeof(int) * (len_lines + 1));
    mask = get_mask(map, mask, nb_lines, len_lines - 1);
    get_position(map, mask, nb_lines, len_lines);
    print_array(map, nb_lines, len_lines);
}

void build_map(char *raw, int map_size, int nb_lines, int len_lines)
{
    char **map = malloc(sizeof(char *) * nb_lines);
    int i = 0;
    int n = 0;

    for (int i = 0; i < nb_lines; i++)
        map[i] = malloc(sizeof(char) * len_lines);
    while (raw[i] != '\n')
        i++;
    for (i++; i < map_size; i++) {
        if (raw[i] == '\n')
            n++;
        else
            map[n][i - n * len_lines - 2] = raw[i];
    }
    sub_get_map(map, nb_lines, len_lines);
}

int get_map(char *filename)
{
    struct stat *s = malloc(sizeof(struct stat));
    char base[100] = "";
    char *path = my_strcat(base, filename);
    int fd = open(path, O_RDONLY);
    int nb_lines = -1;
    int len_lines;
    stat(path, s);
    int map_size = s->st_size;
    char *raw = malloc(sizeof(char) * map_size);
    read(fd, &raw[0], map_size);

    if (fd == -1)
        return 84;
    for (int i = 0; i < map_size; i++)
        if (raw[i] == '\n')
            nb_lines++;
    len_lines = map_size / nb_lines;
    build_map(raw, map_size, nb_lines, len_lines);
    return 0;
}

int main(int argc, char *argv[])
{
    int out = 84;
    if (argc < 2)
        return out;
    else
        out = get_map(argv[1]);
    return out;
}
