/*
** EPITECH PROJECT, 2023
** simple_fonction
** File description:
** simple fonction for error file
*/

#include "lemin.h"

int sup_comment(char **all_info, int i, int j)
{
    for (; all_info[i][j] != '\0'; j++)
        if (all_info[i][j] == '#') {
            all_info[i][j] = '\0';
            j--;
            break;
        }
    return j;
}

int remove_comment_boucle(char **all_info, char **new, int i, int o)
{
    if (all_info[i][0] == '#') {
        if (all_info[i][1] == '#')
            new[o] = my_strdup(all_info[i]);
        else
            return o;
    } else {
        int j = 0;
        j = sup_comment(all_info, i, j);
        new[o] = my_strndupp(all_info[i], j);
    }
    o++;
    return o;
}

char **remove_comment(char **all_info)
{
    int o = 0;
    char **new;

    if (!(new = malloc(sizeof(char *) * (count_line(all_info) + 1)))
    || all_info == NULL)
        return (NULL);
    for (int i = 0; all_info[i] != NULL; i++) {
        o = remove_comment_boucle(all_info, new, i, o);
    }
    new[o] = NULL;
    my_free_array(all_info);
    return (new);
}

char **verif_start_and_end(char **all_info)
{
    int i = 0;
    int start = 0;
    int end = 0;

    if (all_info == NULL)
        return (NULL);
    for (i = 0; all_info[i] != NULL; i++) {
        if (my_strcmp(all_info[i], "##start") == 0)
            start++;
        if (my_strcmp(all_info[i], "##end") == 0)
            end++;
    }
    if (start != 1 || end != 1) {
        write(2, "ERROR: No start or end\n", 24);
        my_free_array(all_info);
        return (NULL);
    }
    return (all_info);
}

char *clean_str(char *str)
{
    int i = 0;
    int o = 0;
    char *new_str;

    if (!(new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) ||
    str == NULL)
        return NULL;
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            continue;
        new_str[o] = str[i];
        o++;
    }
    new_str[o] = '\0';
    free(str);
    return (new_str);
}
