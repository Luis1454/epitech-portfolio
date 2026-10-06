/*
** EPITECH PROJECT, 2023
** my_cd.c
** File description:
** utils for my_cd
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

static int sub_my_cd(char **args, env_node_t *env, int len)
{
    if (len > 2)
        return !my_print_error("cd: Too many arguments.\n");
    if (!my_strcmp(args[1], "-")) {
        args[1] = my_strdup_f(args[1], get_env_value(env, "OLDPWD"));
        if (args[1] == NULL)
            return !my_print_error("cd: OLDPWD not set.\n");
    }
    if (len == 2 && args[1][0] == '$')
        args[1] = my_strdup_f(args[1], get_env_value(env, &args[1][1])
        ? get_env_value(env, &args[1][1]) : "");
    if (len == 1 || (!args[1][1] && contain("~#", args[1][0])))
        args[1] = my_strdup_f(args[1], get_env_value(env, "HOME"));
    if (!is_dir(args[1]))
        return !my_print_error("cd: Not a directory.\n");
    if (chdir(args[1]) == -1) {
        my_print_error("cd: ");
        error_msg(args[1], strerror(errno));
        return 1;
    }
    return 0;
}

int my_cd(char **args, env_node_t *env)
{
    char *path = NULL;
    char *old = NULL;
    int state = 0;

    if ((state = sub_my_cd(args, env, my_arrlen(args))) != 0)
        return state;
    old = my_strdup(get_env_value(env, "PWD"));
    path = get_abs_path();
    if (path == NULL)
        return !my_print_error("cd: Failed to set PWD (malloc failed).\n");
    if (my_setenv((char *[]){"setenv", "PWD", path, NULL}, env)) {
        state = !my_print_error("cd: Failed to set PWD.\n");
    } else if (my_setenv((char *[]){"setenv", "OLDPWD", old, NULL}, env)) {
        my_setenv((char *[]){"setenv", "PWD", old, NULL}, env);
        state = !my_print_error("cd: Failed to set OLDPWD.\n");
    }
    free(path);
    free(old);
    return state;
}
