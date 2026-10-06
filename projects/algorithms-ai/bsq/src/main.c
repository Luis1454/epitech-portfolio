/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"

int double_back(char *map, long n, long len, long i)
{
    for (int j = 1; j <= i; j++)
        if (map[n + len * (i - j) + i] != '.'
        || map[n + len * i + i - j] != '.')
            return 0;
    return 1;
}

long get_score(char *map, long n, long len)
{
    int i = 0;

    for (; map[n + len * i + i] == '.'
    && double_back(map, n, len, i); i++);
    return i;
}

int my_bsq(long size, char *map, long offset, long best)
{
    long pos = 0;
    long mark = 0;
    long lines = 0;
    long len = 0;

    for (long i = offset; map[i]; i++, lines += map[i] == '\n');
    len = (ABS(size) - offset) / lines;
    for (long i = offset; map[i]; i++) {
        if ((mark = get_score(map, i, len)) > best) {
            best = mark;
            pos = i;
        }
        if (mark >= len / 2 && mark >= lines / 2)
            break;
    }
    insert_square(map, best, len, pos);
    write(1, &map[offset], ABS(size) - offset - (size < 0));
    free(map);
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 2 && argc != 3 || argc == 3 && !my_char_isnum(argv[1][0]) ||
    argc == 3 && !only_contain(".o", argv[2]) || argc == 2 && !argv[1][0])
        return 84;
    struct stat *d = malloc(sizeof(struct stat));
    int fd = open(argv[1], O_RDONLY);
    stat(argv[1], d);
    char *map = malloc(sizeof(char) * (d->st_size + 1));
    map[d->st_size] = 0;
    fd != -1 ? read(fd, map, d->st_size), close(fd) : 0;

    if (((fd == -1 || !d->st_size || !is_valid(map, d)) && argc == 2)) {
        free(d);
        free(map);
        return 84;
    } else if (fd == -1)
        return generate_map(d, map, my_getnbr(argv[1]), argv[2]);
    my_bsq(d->st_size, map, skip_to_line(1, map), -1);
    free(d);
    return 0;
}
