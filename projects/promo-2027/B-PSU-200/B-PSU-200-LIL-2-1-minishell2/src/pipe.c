/*
** EPITECH PROJECT, 2023
** pipe.c
** File description:
** pipe functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"
#include <fcntl.h>


int is_builtin(char *cmd)
{
    char *builtins[] = {"cd", "env", "setenv",
    "unsetenv", "exit", "echo", NULL};

    for (int i = 0; builtins[i]; i++)
        if (!my_strcmp(cmd, builtins[i]))
            return 1;
    return 0;
}
