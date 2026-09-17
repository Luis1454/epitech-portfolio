/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** map functions
*/

#include <signal.h>
#include "../include/my.h"
#include "../include/navy.h"

void display_map(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c", map[i][j]);
            j != 7 ? my_printf(" ") : 0;
        }
        my_printf("\n");
    }
}

char **sub_load(char **map, char *line)
{
    for (int j = line[2] - 'A'; j <= line[5] - 'A'; j++) {
        for (int k = line[3] - '1'; k <= line[6] - '1'; k++) {
            map[j][k] = line[0];
        }
    }
    return map;
}

char **load_map(char **map, char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return NULL;
    for (int i = 0; i < 4; i++) {
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        if ((read = getline(&line, &len, file)) == -1)
            return NULL;
        map = sub_load(map, line);
    }
    return map;
}

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 8);
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
    return map;
}
