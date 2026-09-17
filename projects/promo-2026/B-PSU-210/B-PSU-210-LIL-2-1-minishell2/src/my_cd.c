/*
** EPITECH PROJECT, 2021
** my_cd.c
** File description:
** cd command for minishell2
*/

#include "../includes/minishell.h"
#include "../includes/my.h"

int sub_my_cd(Env *env, char *path)
{
    char *str = getcwd(path, 1024);

    if (my_strlen(str) != my_utf_strlen(str)) {
        my_putstr("error: utf-8 not supported\n");
        return 0;
    }
    if (str != NULL) {
        my_setenv(env, "OLDPWD", get_value(env, "PWD"), 3);
        my_setenv(env, "PWD", str, 3);
    }
    return 1;
}

int my_cd(Env *env, char *path)
{
    if (are_equals(path, "."))
        return 1;
    if (are_equals(path, "~"))
        path = get_value(env, "HOME");
    else if (are_equals(path, "-"))
        path = get_value(env, "OLDPWD");
    if (chdir(path)) {
        perror(env->cmd[1]);
        return 0;
    }
    if (!sub_my_cd(env, path))
        return 0;
    get_prompt(env);
    return 1;
}

int check_cd(Env *env)
{
    if (my_arrlen(env->cmd) <= 2)
        my_cd(env, (my_arrlen(env->cmd) == 2 ? env->cmd[1] : "~"));
    else {
        perror("cd");
        return 0;
    }
    return 1;
}
