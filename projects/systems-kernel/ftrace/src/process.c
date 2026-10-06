/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** process
*/

#include "../include/process.h"

int process(char **av)
{
    int ret = 0;
    ftrace_t *ftrace = malloc(sizeof(ftrace_t));

    if (ftrace == NULL)
        return fonction_perror("malloc");
    if (start_tracer(ftrace, av) == 84)
        return 84;
    ret = trace_programme(ftrace);
    free(ftrace);
    return ret;
}
