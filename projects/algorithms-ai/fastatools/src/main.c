/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file
*/

#include "../include/my.h"
#include "../include/fasta.h"
#include <stdio.h>

char *my_strcat_malloc(char *dest, char *src, int len_line)
{
    int len = len_line + my_strlen(dest) + 1;
    char *out = malloc(sizeof(char) * len);
    if (!out)
        return dest;
    int i = 0;

    for (; dest && dest[i]; out[i] = dest[i], i++);
    for (int j = 0; src[j]; out[i] = src[j], j++, i++);
    out[i] = 0;
    dest ? free(dest) : 0;
    return out;
}

void get_stdin_content(char **content)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1)
        *content = my_strcat_malloc(*content, line, len);
    line ? free(line) : 0;
}

void clear_str(char **str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(*str) + 1);
    int i = my_strlen_to(*str, "\n");
    int j = 0;

    if (!tmp)
        return;
    for (; (*str)[i] && (*str)[i] != '>'; i++)
        if (contain("GATCgatc", (*str)[i]))
            tmp[j++] = (*str)[i];
    tmp[j] = 0;
    free(*str);
    *str = my_strdup(tmp);
}

int fasta(char **names, char **arr, int i, int k)
{
    switch (i) {
        case 1:
            return display_one(names, arr);
        case 2:
            return display_two(names, arr);
        case 3:
            return display_three(names, arr);
        case 4:
            return display_four(arr, k);
        case 5:
            return display_five(names, arr);
        default:
            return 84;
    }
    return 84;
}

int main(int ac, char **av)
{
    char **arr = NULL;
    char *content = NULL;
    char **names = NULL;

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return display_usage();
    if (ac < 2 || ac > 3 || !my_str_isnum(av[1])
    || my_getnbr(av[1]) < 0 || my_getnbr(av[1]) > 7)
        return 84;
    get_stdin_content(&content);
    arr = my_str_to_array(content, ">", "");
    names = get_names(content, my_arrlen(arr));
    free(content);
    if (!arr)
        return 84;
    for (int i = 0; arr[i]; i++)
        clear_str(&arr[i]);
    return fasta(names, arr, my_getnbr(av[1]), ac == 3 ? my_getnbr(av[2]) : 0);
}
