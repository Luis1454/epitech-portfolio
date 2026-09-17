/*
** EPITECH PROJECT, 2021
** my_echo.c
** File description:
** echo command for minishell2
*/

#include "../includes/minishell.h"
#include "../includes/my.h"

int my_echo(Env *env)
{
    char *str;
    int i = 1;

    if (my_arrlen(env->cmd) == 2 && env->cmd[1][0] == '$') {
        str = malloc(sizeof(char) * (my_strlen(env->cmd[1])));
        if (str == NULL)
            return 0;
        for (; i < my_strlen(env->cmd[1]); i++)
            str[i - 1] = env->cmd[1][i];
        str[i - 1] = 0;
        my_putstr(get_value(env, str));
        my_putchar('\n');
        free(str);
        return 1;
    }
    return 0;
}
