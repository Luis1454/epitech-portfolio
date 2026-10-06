/*
** EPITECH PROJECT, 2023
** fonc.c
** File description:
** functions
*/
#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

int is_complete_string(char const *str, char *c, int *i)
{
    int nb = *i;
    for (int j = 0; c[j] != '\0'; j++) {
        if (str[*i] != c[j]) {
            *i = nb;
            return -1;
        }
        *i = *i + 1;
    }
    return 0;
}

int cptmot(char const *str, char *c)
{
    int i = 0;
    int cpt = 1;

    for (i = 0; str && str[i] != '\0'; i++) {
        if (is_complete_string(str, c, &i) == 0)
            cpt++;
    }
    return cpt;
}

void getmot(char *result, int *j, char *str, char *c)
{
    int a = 0;
    while (*j < my_strlen(str) && is_complete_string(str, c, j) != 0) {
        result[a] = str[*j];
        a++;
        *j = *j + 1;
    }
    result[a] = '\0';
    return;
}

char **split_str(char *str, char *c)
{
    int e = 0;
    char **result;
    int a = cptmot(str, c);
    result = malloc(sizeof(char *) * my_strlen(str) + 1);
    for (int i = 0; i < a; i++) {
        result[i] = malloc(sizeof(char) * my_strlen(str) + 1);
    }
    int j = 0;
    for (e = 0; e < a ; e++) {
        getmot(result[e], &j, str, c);
    }
    result[e] = NULL;
    return result;
}
