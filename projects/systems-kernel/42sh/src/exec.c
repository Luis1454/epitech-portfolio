/*
** EPITECH PROJECT, 2023
** exec.c
** File description:
** exec functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

int exec_cmd(char *cmd, char **args, char **env_raw)
{
    int pid = fork();
    int status = 0;
    int state = 0;

    if (pid == -1)
        state = -2;
    if (!pid) {
        if (execve(cmd, args, env_raw) == -1) {
            error_msg(cmd, strerror(errno));
            state = -1;
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
        state = handle_status(status);
    }
    free_array(env_raw);
    free(cmd);
    return state;
}

static void sub_check_access(env_node_t *env, char *cmd)
{
    contain("#~", cmd[0]) ? my_print_error(get_env_value(env, "HOME")) : 0;
    contain("#~", cmd[0]) ? my_print_error("/") : 0;
    my_print_error(contain("#~", cmd[0]) ? skip_all_chars(cmd, '/') : cmd);
    my_print_error(": Command not found.\n");
}

int check_access(env_node_t *env, char *cmd, char **args, char **env_raw)
{
    char **paths = contain(".#~", cmd[0]) ? NULL : get_paths(env);
    char *tmp = malloc(sizeof(char) * (BUF_SIZE_ + my_strlen(cmd) + 1));

    !tmp ? free_array(paths) : 0;
    if (tmp == NULL)
        return -1;
    paths = paths == NULL ? my_str_to_array(".", ":", "") : paths;
    for (int i = 0; paths[i]; i++) {
        tmp = my_memset(tmp, 0, my_strlen(paths[i]) + my_strlen(cmd) + 1),
        tmp = my_strcpy(tmp, paths[i]);
        tmp = my_strcat(tmp, "/");
        tmp = my_strcat(tmp, cmd);
        if (!access(tmp, F_OK))
            return exec_cmd(tmp, args, env_raw) - free_array(paths);
    }
    sub_check_access(env, cmd);
    free(tmp);
    free_array(env_raw);
    free_array(paths);
    return 1;
}

int handling(char **args, env_node_t *env, int code)
{
    if (args[0] == NULL)
        return 0;
    if (!my_strcmp(args[0], "exit"))
        return !my_putstr("exit\n") - 1;
    else if (!my_strcmp(args[0], "env"))
        return my_env(env);
    if (!my_strcmp(args[0], "setenv"))
        return my_setenv(args, env);
    else if (!my_strcmp(args[0], "unsetenv"))
        return my_unsetenv(args, env);
    if (!my_strcmp(args[0], "cd"))
        return my_cd(args, env);
    else if (!my_strcmp(args[0], "echo"))
        return my_echo(args, env, code);
    else
        return check_access(env, args[0], args, get_env(env));
}
