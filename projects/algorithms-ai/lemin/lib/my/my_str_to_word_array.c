/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** split a string into an array
*/

#include "libmy.h"

int my_count_words(char const *str, char c)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == c || str[i] == '\n' || str[i + 1] == '\0')
            count++;
    return (count);
}

int my_word_len(char const *str, char c)
{
    int len = 0;

    for (;str[len] != c && str[len] != '\n' && str[len] != '\0'; len++);
    return (len);
}

char **my_str_to_word_array(char const *str, char c)
{
    int j = 0;
    int k = 0;
    char **array = NULL;

    if (str == NULL || c == 0)
        return (NULL);
    if (!(array = malloc(sizeof(char *) * (my_count_words(str, c) + 1))))
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(array[j] = malloc(sizeof(char) * (my_word_len(&str[i], c) + 1))))
            return NULL;
        for (k = 0; str[i] != c && str[i] != '\n' && str[i] != '\0'; k++, i++)
            array[j][k] = str[i];
        array[j][k] = '\0';
        j++;
        if (str[i] == '\0')
            break;
    }
    array[j] = NULL;
    return (array);
}
