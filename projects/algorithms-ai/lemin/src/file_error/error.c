/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** error
*/

#include "lemin.h"

char **error_room(char **all_info, int i)
{
    for (int j = i + 1; all_info[j] != NULL; j++) {
        if (my_strcmp(all_info[i], all_info[j]) == 0)
            return (error(all_info, 4));
    }
    return (all_info);
}

char **verif_same_room(char **all_info)
{
    for (int i = 0; all_info[i] != NULL; i++) {
        if (error_room(all_info, i) == NULL)
            return (NULL);
    }
    return (all_info);
}
