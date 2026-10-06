/*
** EPITECH PROJECT, 2023
** file_error
** File description:
** file error for lemin
*/

#include "lemin.h"

char *read_file(void)
{
    char *buff = malloc(sizeof(char) * 4096);
    int offset = 0;

    if (buff == NULL)
        return (NULL);
    while (read(0, buff + offset, 1) > 0 && offset < 4095) {
        offset++;
    }
    buff[offset] = '\0';
    return (buff);
}

char **verif_number_of_ant_and_rooms(char **all_info)
{
    int nb_ant = 0;

    if (all_info == NULL)
        return (NULL);
    for (int o = 0; all_info[0][o] != '\0'; o++)
        if (all_info[0][o] < '0' || all_info[0][o] > '9')
            return (error(all_info, 0));
    nb_ant = my_getnbr(all_info[0]);
    if (nb_ant <= 0 || nb_ant > 2147483647)
        return (error(all_info, 0));
    if (my_strcmp(all_info[1], "##start") == 0)
        return all_info;
    else {
        if (count_number(all_info[1]) != 3 ||
        my_str_numb(all_info[1], ' ') == 1)
            return error(all_info, 1);
    }
    if (all_info[2] == NULL || all_info[2][0] != '#')
        return (error(all_info, 1));
    return (all_info);
}

char **verif_start(char **all_info)
{
    int i = 0;

    if (all_info == NULL)
        return (NULL);
    for (i = 0; all_info[i] != NULL; i++) {
        if (my_strcmp(all_info[i], "##start") == 0) {
            break;
        }
    }
    for (int o = i + 1; my_strcmp(all_info[o], "##end") != 0; o++) {
        if (count_number(all_info[o]) != 3 ||
        my_str_numb(all_info[o], ' ') == 1)
            return (error(all_info, 2));
    }
    return (all_info);
}

char **verif_end(char **all_info)
{
    int i = 0;
    int t = 0;
    if (all_info == NULL)
        return (NULL);
    for (i = 0; all_info[i] != NULL; i++)
        if (my_strcmp(all_info[i], "##end") == 0)
            break;
    for (int o = i + 1; all_info[o] != NULL; o++) {
        for (int j = 0; all_info[o][j] != '\0'; j++)
            all_info[o][j] == '-' ? t++ : 0;
        if (count_number(all_info[o]) == 3 && t == 0 &&
        my_str_numb(all_info[o], '-') == 0)
            continue;
        if (count_number(all_info[o]) != 2 || t != 1 ||
        (count_number(all_info[o]) == 2 && count_space(all_info[o]) != 0)
        || my_str_numb(all_info[o], '-') == 1)
            return (error(all_info, 3));
        t = 0;
    }
    return (all_info);
}

char **recup_file(void)
{
    char *buff = read_file();
    char **all_info;

    if (buff == NULL ||
    !(all_info = my_str_to_word_array(buff, '\n')))
        return (NULL);
    free(buff);
    if (!(all_info = clean_tab(all_info)) ||
    !(all_info = verif_same_room(all_info)))
        return (NULL);
    if (!(all_info = remove_comment(all_info)))
        return (NULL);
    if (!(all_info = verif_start_and_end(all_info)))
        return (NULL);
    if (!(all_info = verif_number_of_ant_and_rooms(all_info)))
        return (NULL);
    if (!(all_info = verif_start(all_info)) ||
    !(all_info = verif_end(all_info)))
        return (NULL);
    return (all_info);
}
