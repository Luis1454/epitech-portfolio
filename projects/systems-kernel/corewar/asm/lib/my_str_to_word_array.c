/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdarg.h>

int my_strlen_delim(char const *str, char delim_char);

char **my_strtoword_array(char const *str, char delim_char)
{
    int size = my_strlen_delim(str, '\0');
    char **array = malloc(sizeof(char*) * (size + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    array[j] = malloc(sizeof(char) * (size + 1));
    for (; str[i] != '\0'; i++, k++) {
        array[j][k] = str[i];
        array[j][k + 1] = '\0';
        if (str[i] == delim_char) {
            array[j][k] = '\0';
            j++;
            array[j] = malloc(sizeof(char) * (size + 1));
            k = -1;
        }
    }
    j++;
    array[j] = NULL;
    return array;
}

char **my_strtoword_array_muldelim(char const *str, ...)
{
    int size = my_strlen_delim(str, '\0');
    char **array = malloc(sizeof(char*) * (size + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    va_list delim;
    array[j] = malloc(sizeof(char) * (size + 1));
    va_start(delim, str);
    for (; str[i] != '\0'; i++, k++) {
        array[j][k] = str[i];
        array[j][k + 1] = '\0';
        if (va_arg(delim, int) == str[i]) {
            array[j][k] = '\0';
            j++;
            array[j] = malloc(sizeof(char) * (size + 1));
            k = -1;
        }
    }
    array[j + 1] = NULL;
    return array;
}
