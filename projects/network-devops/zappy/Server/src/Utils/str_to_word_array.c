/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** str_to_word_array
*/

#include "../../include/Utils/utils.h"

// split a string into an array of words
char **str_to_word_array(char *str, char *delim)
{
    char **array;
    int cmpt = 0;
    char *token = strtok(str, delim);
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == delim[0])
            cmpt++;
    array = malloc(sizeof(char *) * cmpt + 1);
    if (array == NULL)
        return NULL;
    while (token != NULL) {
        array[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    array[i] = NULL;
    return array;
}
