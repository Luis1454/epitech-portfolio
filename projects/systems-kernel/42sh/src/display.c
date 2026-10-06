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
    my_putstr("\033[0m");
    my_printf("[\033[1;94m%s\033[0m@\033[2;92m%s\033[0m \033[1;96m%s\033[0m]",
    get_env_value(env, "USER"), get_env_value(env, "HOSTNAME"),
    my_strcmp(get_env_value(env, "PWD"), get_env_value(env, "HOME")) ?
    skip_all_chars(get_env_value(env, "PWD"), '/') : "~");
    my_printf("$ ");
}

int display_usage(void)
{
    my_putstr("USAGE :\n\t./mysh\n\t./mysh --help/-h\n");
    my_putstr("DESCRIPTION :\n\tMinishell1 is the first step");
    my_putstr(" to recreate the shell from scratch.\n\n");
    my_putstr("\tIt's a simple shell that can execute basic commands\n");
    my_putstr("\tAny other feature will be added in the next projects\n");
    return 0;
}
