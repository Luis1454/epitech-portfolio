/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file for minishell1
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

int sub_minishell_a(char **input, int *status)
{
    if (input == NULL || *input == NULL)
        return -1;
    if (!(*input)[0]) {
        *status = 0;
        free(*input);
        return -1;
    }
    return 0;
}

int amorce_request(env_node_t *env, char **input, char ***split)
{
    size_t size = BUF_SIZE_;

    signal(SIGINT, handler_ctrl);
    isatty(0) ? display_prompt(env) : 0;
    if (getline(input, &size, stdin) == -1) {
        my_printf("exit\n");
        *input ? free(*input) : 0;
        env ? free_env(env) : 0;
        exit(EXIT_CODE_);
    }
    (*input)[my_strlen(*input) - 1] = 0;
    *split = my_str_to_array(*input, ";\n", "\"");
    return 0;
}

int sub_minishell_b(env_node_t *env, char *input, char **split, int *status)
{
    int out = 0;

    for (int i = 0; split[i]; i++) {
        if ((out = handle_and(env, split[i], status)) == -1) {
            input ? free(input) : 0;
            split ? free_array(split) : 0;
            env ? free_env(env) : 0;
            return out;
        }
    }
    return -42;
}

int minishell(env_node_t *env, int state, int out, int status)
{
    char **split = NULL;
    char *input = NULL;

    while (state) {
        amorce_request(env, &input, &split);
        if ((out = sub_minishell_a(split, &status)) < 0)
            continue;
        if (out > 0) {
            input ? free(input) : 0;
            split ? free_array(split) : 0;
            env ? free_env(env) : 0;
            return ERR_CODE_;
        }
        if ((out = sub_minishell_b(env, input, split, &status)) != -42)
            return 0;
        state = isatty(0);
        split ? free_array(split) : 0;
    }
    return exit_shell(env, status, input);
}

int main(int argc, char **argv, char **env_raw)
{
    env_node_t *env = NULL;
    int is_usage = (!my_strcmp(argv[1], "-h")
    || !my_strcmp(argv[1], "--help")) && argc == 2;

    if (is_usage)
        return display_usage();
    if (env_raw == NULL) {
        my_print_error("Error: env is empty.\n");
        return ERR_CODE_;
    } else if (argc != 1 && isatty(0)) {
        my_print_error("Error: too many arguments.\n");
        return ERR_CODE_;
    }
    env = init_env_list(env_raw);
    if (my_unsetenv((char *[]){"unsetenv", "OLDPWD", NULL}, env)) {
        free_env(env);
        return !my_print_error("Error: OLDPWD unset failed.\n") + 84;
    }
    return minishell(env, 1, 0, 0);
}
