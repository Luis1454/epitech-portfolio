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

    for (int i = 0, n = 0; input[i] && n < size; i++)
        sub_redir_types(input, types, &i, &n);
    return types;
}

char *push_str(char *dest, char const *str)
{
    int len = my_strlen(dest);
    int len2 = my_strlen(str);
    char *out = malloc(sizeof(char) * (len + len2 + 1));

    for (int i = 0; str[i]; i++)
        out[i] = str[i];
    for (int i = 0; dest[i]; i++)
        out[i + len2] = dest[i];
    out[len + len2] = 0;
    free(dest);
    return out;
}

int in_redirect(env_node_t *env, char **split, int *i, int *status)
{
    char *signs[] = {"<", ">", "<<", ">>"};
    char **args = NULL;
    int fd = 0;
    char *buf = malloc(sizeof(char) * 8192);

    if (my_strcmp(signs[i[1]], "<"))
        return 0;
    fd = open(split[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    buf[read(fd, buf, 8192)] = 0;
    close(fd);
    buf = push_str(buf, split[i[0]]);
    args = my_str_to_array(buf, " \t\n");
    *status = handling(args, env, *status);
    return 0;
}

int out_redirect(env_node_t *env, char **split, int *i, int *status)
{
    char *signs[] = {"<", ">", "<<", ">>"};
    pid_t pid = 0;
    int fd = 0;

    if (my_strcmp(signs[i[1]], ">") && my_strcmp(signs[i[1]], ">>"))
        return 0;
    if ((fd = open(split[i[0] + 1], O_WRONLY | O_CREAT |
    (!my_strcmp(signs[i[1]], ">") ? O_TRUNC : O_APPEND), 0644)) == -1)
        return 1;
    if ((pid = fork()) == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
        *status = handling(my_str_to_array(split[i[0]], " \t"), env, *status);
        exit(*status);
    } else if (pid < 0)
        return 1;
    waitpid(pid, status, 0);
    return close(fd) * 0;
}
