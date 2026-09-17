/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** bsq utils file
*/

#include "../include/my.h"

long skip_to_line(int line, char *str)
{
    long i = 0;

    for (; line; i++, line--)
        for (; str[i] && str[i] != '\n'; i++);
    return i;
}

int insert_square(char *map, long best, long len, long pos)
{
    for (long x = 0; x < best; x++)
        for (long y = 0; y < best; y++)
            map[pos + y * len + x] = 'x';
    return 0;
}

int generate_map(struct stat *d, char *map, int size, const char *pattern)
{
    long len = my_strlen(pattern);
    long i = 0;
    long n = 0;

    free(d);
    if (map != NULL)
        free(map);
    if (!size || !only_contain(".o", pattern))
        return 84;
    size += 2;
    map = malloc(sizeof(char) * ((size - 2) * (size - 2) + size));
    for (; i < (size - 2) * (size - 2) + size - 1; i++) {
        map[i] = !((i + n) % size) ? '\n' : pattern[(i - n) % len];
        n += !((i + n) % size);
    }
    map[i] = 0;
    return my_bsq(-((size - 2) * (size - 2) + size), map, 1, -1);
}

int is_valid(char *str, struct stat *d)
{
    int val = my_getnbr(str);
    int nb = 0;
    long offset = skip_to_line(1, str);

    if (!val)
        return 0;
    for (int i = 0, len = 0; i < d->st_size; i++, nb += str[i] == '\n') {
        if (!my_char_isnum(str[i]) && str[i] != 'o'
        && str[i] != '.' && str[i] != '\n')
            return 0;
        if (str[i] == '\n' && i > offset && len != (d->st_size - offset) / val)
            return 0;
        len *= !(str[i] == '\n');
        len++;
    }
    return 1;
}
