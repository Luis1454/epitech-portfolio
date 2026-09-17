/*
** EPITECH PROJECT, 2023
** minishell.h
** File description:
** minishell includes
*/

#pragma once

#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#ifndef PATH_MAX_
    #define PATH_MAX_ 4096
#endif /* PATH_MAX_ */

#ifndef BUF_SIZE_
    #define BUF_SIZE_ 4096
#endif /* BUF_SIZE_ */

#ifndef EXIT_CODE_
    #define EXIT_CODE_ 0
#endif /* EXIT_CODE_ */

#ifndef ERR_CODE_
    #define ERR_CODE_ 84
#endif /* ERR_CODE */

#ifndef MINISHELL_H_
    #define MINISHELL_H_

typedef struct env_node {
    char *name;
    char *value;
    struct env_node *next;
    struct env_node *prev;
} env_node_t;

int is_dir(char *path);

void error_msg(char *cmd, char *msg);

void display_prompt(env_node_t *env);

int display_usage(void);

int my_echo(char **args, env_node_t *env, int status);

int my_env(env_node_t *env);

void free_env(env_node_t *env);

int free_array(char **array);

int exec_cmd(char *cmd, char **args, char **env_raw);

int check_access(env_node_t *env, char *cmd, char **args, char **env_raw);

int handling(char **args, env_node_t *env, int code);

char *get_env_value(env_node_t *env_list, char *name);

char **get_paths(env_node_t *env);

char *get_abs_path(void);

char **get_env(env_node_t *env);

char *skip_all_chars(char *str, char c);

int handle_status(int status);

int minishell(env_node_t *env);

int init_minishell(char **env_raw);

int my_cd(char **args, env_node_t *env, int status);

env_node_t *init_env_list(char **env);

env_node_t *add_node(env_node_t *env_list, char *env);

env_node_t *append_node(env_node_t *env_list, char *var, char *value);

env_node_t *drop_node(env_node_t *env_list, env_node_t *node);

int my_unsetenv(char **args, env_node_t *env);

int my_setenv(char **args, env_node_t *env);

#endif /* !MINISHELL_H_ */
