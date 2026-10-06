/*
** EPITECH PROJECT, 2023
** echo.c
** File description:
** echo function
*/

#include "../include/my.h"
#include "../include/minishell.h"

int sub_echo_a(char **args, int i, int *j, int status)
{
    if (args[i][*j] == '\\') {
        my_putchar(args[i][*j++ + 1]);
        return 0;
    }
    if (!my_strncmp(&args[i][*j], "$?", 2)) {
        my_put_nbr(status, __INT_MAX__);
        (*j)++;
        return 0;
    }
    return 1;
}

int sub_echo_b(env_node_t *env, char **args, char *tmp, triplet_t *p)
{
    if (args[*p->a][*p->b] == '$') {
        tmp = my_strndup(&args[*p->a][*p->b + 1],
        my_alphanumlen(&args[*p->a][*p->b + 1]));
        if (tmp == NULL) {
            my_print_error("Error: malloc failed\n");
            return 1;
        }
        my_putstr(get_env_value(env,  tmp)
        ? get_env_value(env, tmp) : "");
        *p->b += my_alphanumlen(&args[*p->a][*p->b + 1]);
        free(tmp);
        return 0;
    }
    my_putchar(args[*p->a][*p->b]);
    return 0;
}

int my_echo(char **args, env_node_t *env, int status)
{
    char *tmp = NULL;
    int len = my_arrlen(args);

    for (int i = 1; i < len; i++) {
        for (int j = 0; args[i][j]; j++) {
            status = sub_echo_a(args, i, &j, status)
            ? sub_echo_b(env, args, tmp, &(triplet_t){&i, &j, NULL}) : 0;
        }
        if (i != len - 1)
            my_putchar(' ');
    }
    my_putchar('\n');
    return 0;
}
