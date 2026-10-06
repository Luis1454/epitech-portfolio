/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file for minishell1
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

int handle_status(int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status) + (WIFSIGNALED(status) ? 128 : 0);
    if (WIFSIGNALED(status)) {
        my_print_error(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_print_error(" (core dumped)");
        my_print_error("\n");
        return WTERMSIG(status) + 128;
    } else if (WIFSTOPPED(status)) {
        my_print_error("Stopped (signal ");
        my_put_nbr_err(WSTOPSIG(status), __INT_MAX__);
        my_print_error(")\n");
        return WSTOPSIG(status);
    }
    if (WIFCONTINUED(status)) {
        my_print_error(strsignal(status));
        return 0;
    } else if (!WIFEXITED(status))
        my_print_error("Unknown status.\n");
    return 0;
}

int sub_minishell_a(env_node_t *env, char **input, int *status)
{
    size_t size = BUF_SIZE_;

    isatty(0) ? display_prompt(env) : 0;
    if (getline(input, &size, stdin) == -1) {
        my_printf("\n");
        exit(EXIT_CODE_);
    }
    if (*input == NULL)
        return ERR_CODE_;
    (*input)[my_strlen(*input) - 1] = 0;
    if (!(*input)[0]) {
        *status = 0;
        free(*input);
        return -1;
    }
    return 0;
}

int sub_minishell_b(char ***args, env_node_t *env, char **input, int *status)
{
    if ((*args = my_str_to_array(*input, " \t")) == NULL) {
        free(*input);
        return ERR_CODE_;
    }
    if ((*status = handling(*args, env, *status)) < 0) {
        free(*input);
        free_array(*args);
        return *status != -1 ? ERR_CODE_ : 0;
    }
    return -1;
}

int minishell(env_node_t *env)
{
    char *input = NULL;
    char **args = NULL;
    int status = 0;
    int state = 1;
    int out = 0;

    while (state) {
        if ((out = sub_minishell_a(env, &input, &status)) < 0)
            continue;
        if (out > 0)
            return ERR_CODE_;
        if ((out = sub_minishell_b(&args, env, &input, &status)) >= 0)
            return out;
        state = isatty(0);
    }
    free(input);
    free_array(args);
    free_env(env);
    return isatty(0) ? ERR_CODE_ : status;
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
    return minishell(env);
}
