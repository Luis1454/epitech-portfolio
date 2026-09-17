/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

void error_msg(char *cmd, char *msg)
{
    if (cmd == NULL || msg == NULL)
        return;
    my_print_error(cmd);
    my_print_error(": ");
    my_print_error(msg);
    my_print_error("\n");
}

void display_prompt(env_node_t *env)
{
    my_printf("[%s@%s %s]$ ", get_env_value(env, "USER"),
    get_env_value(env, "HOSTNAME"),
    my_strcmp(get_env_value(env, "PWD"), get_env_value(env, "HOME")) ?
    skip_all_chars(get_env_value(env, "PWD"), '/') : "~");
}

int display_usage(void)
{
    my_putstr("USAGE :\n\t./mysh\n\t./mysh --help/-h\n");
    my_putstr("DESCRIPTION :\n\tMinishell1 is the first step");
    my_putstr(" to recreate the tcsh shell from scratch.\n\n");
    my_putstr("\tIt's a simple shell that can execute basic commands\n");
    my_putstr("\tlike ls, cd, pwd, env, setenv, unsetenv and exit.\n\n");
    my_putstr("\tAny other feature will be added in the next projects\n");
    my_putstr("\tsuch as pipes, redirections, separators, etc.\n");
    return 0;
}

int my_echo(char **args, env_node_t *env, int status)
{
    int len = my_arrlen(args);

    for (int i = 1; i < len; i++) {
        if (!my_strcmp(args[i], "$?"))
            my_put_nbr(status, __INT_MAX__);
        if (my_strcmp(args[i], "$?"))
            my_putstr(get_env_value(env, &args[i][1]) ? get_env_value(env,
            &args[i][1]) : args[i][0] == '$' ? "" : args[i]);
        if (i != len - 1)
            my_putchar(' ');
    }
    my_putchar('\n');
    return 0;
}
