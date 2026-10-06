/*
** EPITECH PROJECT, 2022
** task 04
** File description:
** C pool day 08
*/

#include "../../include/my.h"

int count_nbr_words(char const *str, char add)
{
    int i = 0, count = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == add || str[i] == '\n' || str[i] == '\0')
            count++;
    }
    return (count);
}

int get_array_size(char const *str, char add)
{
    int len = 0;

    for (;str[len] != add && str[len] != '\n' && str[len] != '\0'; len++);
    return (len);
}

char **my_str_to_word_array(char const *str, char add)
{
    char **tab = malloc(sizeof(char *) * (1));
    tab[0] = NULL;
    if (str == NULL)
        return tab;
    char **dest = malloc(sizeof(char *) * (count_nbr_words(str, add) + 2));
    int i = 0, j = 0, k = 0;
    for (; str[i] != '\0'; i++) {
        dest[j] = malloc(sizeof(char) * (get_array_size(&str[i], add) + 1));
        for (k = 0; str[i] != add && str[i] != '\n' && str[i] != '\0'; k++) {
            dest[j][k] = str[i];
            i++;
        }
        dest[j][k] = '\0';
        j++;
        if (str[i] == '\0')
            break;
    }
    dest[j] = NULL;
    return (dest);
}
