/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** handle functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

int handle_redirect(env_node_t *env, char *input, int *status)
{
    char **split = my_str_to_array(input, "<>");
    int *types = get_redir_types(input, my_strlen(input));
    int len = my_arrlen(split);
    int ptr[] = {0, 0};

    for (int i = 0; i < len - 1; i++) {
        ptr[0] = i;
        ptr[1] = types[i];
        clear_str(split[i + 1]);
        if (in_redirect(env, split, ptr, status)
        || out_redirect(env, split, ptr, status)) {
            free(types);
            free_array(split);
            *status = 1;
            return -1;
        }
    }
    free_array(split);
    free(types);
    return len == 1 ? handle_pipes(env, input, status) : -1;
}

int handle_pipes(env_node_t *env, char *input, int *status)
{
    char **split = my_str_to_array(input, " \t");
    int size = my_arrlen(split);

    if (split == NULL)
        return 1;
    *status = handling(split, env, *status);
    free_array_n(split, my_strcmp(split[0], "cd") ? 2 : size);
    return *status >= 0 ? -1 : 0;
}

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

int exit_shell(env_node_t *env, int status, char *input)
{
    free(input);
    free_env(env);
    return isatty(0) ? ERR_CODE_ : status;
}

void clear_str(char *str)
{
    char **split = my_str_to_array(str, " \t");

    if (split == NULL)
        return;
    free(str);
    str = my_strdup(split[0]);
    free_array(split);
}
