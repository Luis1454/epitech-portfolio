/*
** EPITECH PROJECT, 2021
** command.c
** File description:
** command file for minishell2
*/

#include "../includes/minishell.h"
#include "../includes/my.h"

void reset_cmd(Env *env)
{
    for (int i = 0; env->cmd[i] != NULL; i++)
        for (int j = 0; env->cmd[i][j]; j++) {
            env->cmd[i][j] = 0;
        }
}

void split_cmd(Env *env, char *str)
{
    int x = 0;
    int y;
    int i = 0;

    reset_cmd(env);
    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        for (y = 0; str[i] != ' ' && str[i] != '\t'
        &&  str[i]; i++, y++)
            env->cmd[x][y] = str[i];
        env->cmd[x][y] = 0;
        x++;
    };
}

int run_cmd(Env *env)
{
    char **tab = my_str_to_word_array(get_value(env, "PATH"), ':');
    char *str;

    for (int i = 0; tab[i] != NULL; i++) {
        str = my_weak_strcat(my_weak_strcat(tab[i], "/"), env->cmd[0]);
        if (execve(str, env->cmd, env->arr) != -1) {
            free_str_arr(tab);
            return 1;
        }
    }
    if (execve(env->cmd[0], env->cmd, env->arr) != -1) {
        free_str_arr(tab);
        return 1;
    }
    free_str_arr(tab);
    return 0;
}

int sub_get_cmd(Env *env,int pid, int state)
{
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 0;
    } else if (pid > 0) {
        waitpid(pid, &state, 0);
        kill(pid, 0);
    }
    if (!pid && !run_cmd(env))
        perror(env->cmd[0]);
    return 1;
}

int get_cmd(Env *env, char *buf)
{
    int v = 0;
    pid_t pid = 0;
    int state = 0;
    char **split = my_str_to_word_array(buf, '|');

    for (int i = 0; split[i] != NULL; i++) {
        // printf("%i : %s\n", i, split[i]);
        env->cmd = my_str_to_word_array(split[i], ' ');
        are_equals(env->cmd[0], "cd") ? check_cd(env), v = 1 : 0;
        are_equals(env->cmd[0], "echo") ? v = my_echo(env) : 0;
        are_equals(env->cmd[0], "env") ? my_env(env), v = 1 : 0;
        (are_equals(env->cmd[0], "setenv") || are_equals(env->cmd[0], "unsetenv"))
        ? check_args(env), v = 1 : 0;
        if (!v && my_strlen(buf)) {
            sub_get_cmd(env, pid, state);
            v = 1;
        }
    }
    return v;
}
