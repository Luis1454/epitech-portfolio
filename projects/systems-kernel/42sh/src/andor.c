/*
** EPITECH PROJECT, 2023
** andor.c
** File description:
** andor functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

char **get_list_command(char *input)
{
    char **split = split_str(input, "&&");
    int cpt = 1;
    int ind = 0;
    for (int i = 0; split[i] != NULL; i++) {
        char **s = split_str(split[i], "||");
        for (int j = 0; s[j] != NULL; j++)
            cpt++;
    }
    char **result = malloc(sizeof(char *) * cpt);
    for (int i = 0; split[i] != NULL; i++) {
        char **s = split_str(split[i], "||");
        for (int j = 0; s[j] != NULL; j++) {
            result[ind] = s[j];
            ind++;
        }
    }
    result[ind] = NULL;
    return result;
}

void execute_and(int *status, char **command, env_node_t *env, int *exec)
{
    if (*status == 0) {
        *status = handle_redirect(env, command[*exec], status);
        *exec = *exec + 1;
    }
}

void execute_or(int *status, char **command, env_node_t *env, int *exec)
{
    if (*status != 0) {
        *status = handle_redirect(env, command[*exec], status);
        *exec = *exec + 1;
    }
}
