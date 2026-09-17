/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for minishell2
*/

#include "../includes/minishell.h"
#include "../includes/my.h"

int sub_minishell(Env *env, char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        if (are_equals(cmd[i], "exit"))
            return 0;
        if (!get_cmd(env, cmd[i]) && my_strlen(cmd[i])) {
            my_putstr(cmd[i]);
            my_putstr(" : invalid command\n");
        }
    }
    return 1;
}

int minishell(Env *env)
{
    size_t buf_size = 4096;
    char *buf = malloc(sizeof(char) * buf_size);
    char **cmd = malloc(sizeof(char) * buf_size);

    env->state = 0;
    while (!env->state) {
        buf = NULL;
        my_putstr(env->prompt);
        if (getline(&buf, &buf_size, stdin) == -1)
            return 84;
        buf[my_strlen(buf) - 1] = 0;
        cmd = my_str_to_word_array(buf, 59);
        if (!sub_minishell(env, cmd))
            return 0;
    }
    free(buf);
    free_str_arr(cmd);
    return env->state;
}

int main(int argc, char *argv[], char **arr)
{
    Env *env = malloc(sizeof(Env));

    (void) argc;
    (void) argv;
    init_env(env, arr);
    minishell(env);

    free(env);
    return env->state;
}
