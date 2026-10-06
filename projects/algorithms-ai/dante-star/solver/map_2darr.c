/*
** EPITECH PROJECT, 2022
** load_2d_arr_from_file.c
** File description:
** map into a 2d arr
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void fill(char *buffer, char *map)
{
    int i = 0;

    for (; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
        map[i] = buffer[i];
    }
    map[i] = '\0';
}

char **fill_map(char *buffer)
{
    int i = 0;
    int len = 0;
    char **map;

    map = malloc(sizeof(char *) * (nbr_line(buffer) + 1));
    for (i = 0; buffer[len] != '\0' && i < nbr_line(buffer); i++) {
        map[i] = malloc(sizeof(char) * (line_len(&buffer[len]) + 1));
        fill(&buffer[len], map[i]);
        len += line_len(&buffer[len]);
        if (buffer[len] == '\n')
            len++;
    }
    map[i] = NULL;
    return map;
}

int check(int fd, int size)
{
    if (fd == -1) {
        my_putstr("Error with the opening\n");
        return 84;
    }
    if (size == 0) {
        my_putstr("the map have no content");
        return 84;
    }
    return 0;
}

char **map_2darr(char const *filepath)
{
    struct stat st;
    stat(filepath, &st);
    int fd;
    int size = st.st_size;
    char *buffer;
    char **map;

    buffer = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    check(fd, size);
    read(fd, buffer, size);
    buffer[size] = '\0';
    map = fill_map(buffer);
    close(fd);
    free(buffer);
    return map;
}
