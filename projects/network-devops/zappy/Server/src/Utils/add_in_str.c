/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** add_in_str
*/

#include "../../include/Utils/utils.h"

// add a string in another string
char *add_in_str(char *ref, char *to_add)
{
    char *str = malloc(sizeof(char) * BUFFER_SIZE);
    int i = 0;
    int j = 0;

    for (; ref[i] != '\0'; i++)
        str[i] = ref[i];
    for (; to_add[j] != '\0'; j++) {
        str[i] = to_add[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
