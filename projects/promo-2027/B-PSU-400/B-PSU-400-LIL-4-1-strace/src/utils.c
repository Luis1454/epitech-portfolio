/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils
*/

#include "../include/strace.h"

int get_nb_vars(const char **env)
{
    int i = 0;

    while (env[i])
        i++;
    return i;
}

char *getpath(const char **env)
{
    int i = 0;

    while (env[i]) {
        if (!strncmp(env[i], "PATH=", 5))
            return (char *)&env[i][5];
        i++;
    }
    return "/bin:/usr/bin";
}

static int check_s(char **argv, args_t *args, int *i)
{
    if (!strcmp(argv[*i], "-s")) {
        args->arg_s = 1;
        (*i)++;
    }
    if (!strcmp(argv[*i], "-p")) {
        args->arg_p = 1;
        (*i)++;
        return 1;
    }
    return 0;
}

int get_args(int argc, char *argv[], args_t *args)
{
    int n = 0;

    args->size = 32;
    for (int i = 1; i < argc; i++) {
        n = check_s(argv, args, &i);
        if (n)
            args->arg_p = 1;
        if (n && argc < i)
            return 1;
        if (n) {
            args->pid = atoi(argv[i]);
            continue;
        }
        if (argc < i)
            return 1;
        args->av = &argv[i];
        break;
    }
    return args->size < 0 || (!args->arg_p && !args->av);
}
