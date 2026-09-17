/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file
*/

#include "../includes/sokoban.h"
#include "../includes/my.h"

char **get_map(char *str)
{
    char **map = malloc(sizeof(char *) * my_strlen(str));
    int n = 0;
    int p = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (!contain(str[i], " #OXP\n"))
            return NULL;
        map[i] = malloc(sizeof(char) * my_strlen(str));
        if (str[i] == '\n') {
            map[n][p] = 0;
            p = 0;
            n++;
        } else {
            map[n][p] = str[i];
            p++;
        }
    }
    return map;
}

void print_map(Map *map)
{
    for (int i = 0; map->datas[i][0]; i++) {
        for (int j = 0; map->datas[i][j]; j++) {
            map->player.X = map->datas[i][j] == 'P' ? i : map->player.X;
            map->player.Y = map->datas[i][j] == 'P' ? j : map->player.Y;
            printw("%c", map->datas[i][j]);
            refresh();
        }
        printw("\n");
        refresh();
    }
}

void place_player(Map map)
{
    for (int i = 0; map.datas[i][0]; i++)
        for (int j = 0; map.datas[i][j]; j++)
            map.datas[i][j] = map.datas[i][j] == 'P' ? ' ' : map.datas[i][j];
    map.datas[map.player.X][map.player.Y] = 'P';
}

int main(int argc, char const *argv[])
{
    struct stat *s = malloc(sizeof(struct stat));
    int fd = open(argv[1], O_RDONLY);
    stat(argv[1], s);
    int map_size = s->st_size;
    char *raw = malloc(sizeof(char) * map_size);
    read(fd, &raw[0], map_size);

    if (argc != 2 || fd == -1)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        fd = open("readme.usage", O_RDONLY);
        read(fd, &raw[0], 1000);
        my_putstr(raw);
        return 0;
    }
    initscr();
    keypad(stdscr, TRUE);
    return sub_main(raw);
}
