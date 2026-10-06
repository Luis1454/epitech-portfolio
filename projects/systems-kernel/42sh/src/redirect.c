/*
** EPITECH PROJECT, 2023
** redirect.c
** File description:
** redirection handling
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"
#include <fcntl.h>

static void sub_redir_types(char *input, int *types, int *i, int *n)
{
    int cp = *i;

    if (!my_strncmp(&input[cp], "<<", 2)) {
        types[(*n)++] = _D_IN;
        i += 2;
    }
    if (!my_strncmp(&input[cp], ">>", 2)) {
        types[(*n)++] = _D_OUT;
        i += 2;
    }
    if (!my_strncmp(&input[cp], "<", 1)) {
        types[(*n)++] = _IN;
        i++;
    }
    if (!my_strncmp(&input[cp], ">", 1)) {
        types[(*n)++] = _OUT;
        i++;
    }
}

int *get_redir_types(char *input, int size)
{
    int *types = malloc(sizeof(int) * size);
    if (!types)
        return NULL;
    for (int i = 0, n = 0; input[i] && n < size; i++)
        sub_redir_types(input, types, &i, &n);
    return types;
}

int sub_in(env_node_t *env, char **split, int *status, int fd)
{
    char **args = NULL;
    pid_t pid = 0;

    if ((pid = fork()) == -1)
        return !my_print_error("Unable to fork\n");
    if (pid)
        return waitpid(pid, status, 0) == -1 ?
        !my_print_error("Unable to wait for subprocess\n") : 0;
    if ((fd = open(split[1], O_RDONLY)) == -1) {
        my_print_error("Unable to open file\n");
        free_mem(env, split, args);
        exit(1);
    } else if (dup2(fd, STDIN_FILENO) == -1)
        return !my_print_error("Unable to redirect the input\n");
    close(fd);
    args = my_str_to_array(split[0], " \t", "\"");
    *status = handling(args, env, *status);
    free_mem(env, split, args);
    exit(*status);
}

int in_redirect(env_node_t *env, char **split, int *i, int *status)
{
    char *signs[] = {"<", ">", "<<", ">>", NULL};

    if (!my_strcmp(signs[i[1]], "<"))
        return sub_in(env, split, status, 0);
    return 0;
}

int out_redirect(env_node_t *env, char **split, int *i, int *status)
{
    char *signs[] = {"<", ">", "<<", ">>"};
    pid_t pid = 0;
    int fd = 0;

    if (i[1] >= 4)
        return !my_print_error("Invalid redirection\n");
    if (my_strcmp(signs[i[1]], ">") && my_strcmp(signs[i[1]], ">>"))
        return 0;
    if ((fd = open(split[i[0] + 1], O_WRONLY | O_CREAT |
    (!my_strcmp(signs[i[1]], ">") ? O_TRUNC : O_APPEND), 0644)) == -1)
        return 1;
    if ((pid = fork()) == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
        *status = handling(my_str_to_array(
        split[i[0]], " \t", "\""), env, *status);
        exit(*status);
    } else if (pid < 0)
        return 1;
    return waitpid(pid, status, 0) && close(fd) && FALSE;
}
