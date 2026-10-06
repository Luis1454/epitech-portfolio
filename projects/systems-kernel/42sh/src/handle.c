/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** handle functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

int handle_and(env_node_t *env, char *input, int *status)
{
    char **command = get_list_command(input);
    int exec = 1;
    *status = handle_redirect(env, command[0], status);
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '&' && i + 1 < my_strlen(input) && input[i + 1] == '&'
        && command[exec] != NULL)
            execute_and(status, command, env, &exec);
        if (input[i] == '|' && i + 1 < my_strlen(input) && input[i + 1] == '|'
        && command[exec] != NULL)
            execute_or(status, command, env, &exec);
    }
    return *status;
}

int handle_redirect(env_node_t *env, char *input, int *status)
{
    char **split = my_str_to_array(input, "<>", "\"");
    int *types = get_redir_types(input, my_strlen(input));
    int len = my_arrlen(split);
    int ptr[] = {0, 0};

    for (int i = 0; i < len - 1; i++) {
        ptr[0] = i;
        ptr[1] = types[i];
        clear_str(&split[i + 1]);
        if (in_redirect(env, split, ptr, status)
        || out_redirect(env, split, ptr, status)) {
            free_array(split);
            free(types);
            return *status;
        }
    }
    free_array(split);
    free(types);
    return len <= 1 ? handle_pipes(env, input, status) : 0;
}

int handle_pipes(env_node_t *env, char *input, int *status)
{
    char **split = my_str_to_array(input, " \t<>", "\"");
    int size = my_arrlen(split);

    if (split == NULL || format_split(split, size, '\"'))
        return 1;
    for (int i = 0; split[i]; i++)
        drop_quotes(&(split[i]));
    do_pipes(env, split, status);
    free_array_n(split, my_strcmp(split[0], "cd") ? 2 : size);
    return *status;
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
