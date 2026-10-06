/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file
*/

#include "../includes/tetris.h"
#include "../includes/my.h"

int check_after_dot(char *A, char *B)
{
    int j;

    for (j = 0; j < my_strlen(A); j++)
        if (A[j] == '.')
            break;
    if (j == my_strlen(A))
        return 0;
    for (int i = 0; i < my_strlen(B); i++)
        if (B[i] != A[j + i])
            return 0;
    return 1;
}

void print_debug(Game *g)
{
    print_options(g->opt);
    print("Number of tetriminos: ", g->nb_pieces, "\n");
    for (int i = 0; i < g->nb_pieces; i++) {
        strprint("Tetriminos '", g->pieces[i].name, "': ");
        if (g->is_fake[i])
            my_putstr("error\n");
        else {
            my_putstr("size ");
            nprint(g->pieces[i].size.x, "*", g->pieces[i].size.y);
            print(", color ", g->pieces[i].color, "\n");
            print_map(g, i);
        }
    }
}

void main_loop(Game *g, char *raw)
{
    struct stat *s = malloc(sizeof(struct stat));
    char *path = malloc(sizeof(char) * 1000);
    char base[] = "tetriminos/";
    DIR *dir = opendir(base);
    struct dirent *rd;
    int fd;

    while ((rd = readdir(dir)))
        if (rd->d_name[0] != '.'
        && check_after_dot(rd->d_name, ".tetrimino")) {
            g->pieces[g->nb_pieces].name = get_until_char(rd->d_name, '.');
            path = my_strcat(base, rd->d_name);
            fd = open(path, O_RDONLY);
            stat(base, s);
            read(fd, raw, s->st_size);
            raw[s->st_size] = 0;
            get_piece(g, raw);
        }
}

int sub_main(int argc, char **argv, char *raw)
{
    Game *g = malloc(sizeof(Game));

    init(g);
    g->opt = init_options();
    get_options(argc, argv, g->opt);
    main_loop(g, raw);

    if (g->opt->debug)
        print_debug(g);
    for (int i = 0; g->nb_pieces; i++)
        if (!g->is_fake[i])
            return 0;
    return 84;
}

int main(int argc, char **argv)
{
    int fd;
    char ch = 0;
    char *raw = malloc(sizeof(char) * 1000);

    if (argc < 2 || fd == -1)
        return 84;
    if (!my_strcmp(argv[1], "-h") || !my_strcmp(argv[1], "--help")) {
        fd = open("readme.usage", O_RDONLY);
        read(fd, &raw[0], 1000);
        my_putstr(raw);
        return 0;
    }
    
    return sub_main(argc, argv, raw);
}
