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

typedef struct triplet {
    int *a;
    int *b;
    int *c;
} triplet_t;

enum redir_type {
    _IN,
    _OUT,
    _D_IN,
    _D_OUT
};

int is_dir(char *path);

int count_char(const char *str, char c);

void error_msg(char *cmd, char *msg);

void display_prompt(env_node_t *env);

int display_usage(void);

int my_alphanumlen(const char *str);

int format_split(char **split, int len, char c);

int my_echo(char **args, env_node_t *env, int status);

int my_env(env_node_t *env);

void free_env(env_node_t *env);

int free_array(char **array);

int exec_cmd(char *cmd, char **args, char **env_raw);

int check_access(env_node_t *env, char *cmd, char **args, char **env_raw);

int handling(char **args, env_node_t *env, int code);

char *replace_first(char *str, char old, char new);

char *replace_last(char *str, char old, char new);

char *get_env_value(env_node_t *env_list, char *name);

char **get_paths(env_node_t *env);

char *get_abs_path(void);

char **get_env(env_node_t *env);

char *skip_all_chars(char *str, char c);

int handle_status(int status);

int minishell(env_node_t *env, int state, int out, int status);

int my_cd(char **args, env_node_t *env);

int append_array(char ***arr, char *str);

env_node_t *init_env_list(char **env);

env_node_t *add_node(env_node_t *env_list, char *env);

env_node_t *append_node(env_node_t *env_list, char *var, char *value);

env_node_t *drop_node(env_node_t *env_list, env_node_t *node);

int my_unsetenv(char **args, env_node_t *env);

int my_setenv(char **args, env_node_t *env);

int sub_minishell_b(env_node_t *env, char *input, char **split, int *status);

int handle_pipes(env_node_t *env, char *input, int *status);

int *get_redir_types(char *input, int size);

void clear_str(char **str);

void drop_quotes(char **str);

int in_redirect(env_node_t *env, char **split, int *i, int *status);

int out_redirect(env_node_t *env, char **split, int *i, int *status);

int free_array_n(char **array, int n);

int handle_redirect(env_node_t *env, char *input, int *status);

char *my_strdup_f(char *dest, char const *src);

int exit_shell(env_node_t *env, int status, char *input);

int handle_and(env_node_t *env, char *input, int *status);

int do_pipes(env_node_t *env, char **tab, int *status);

int check_pipe_error(int *fd, pid_t pid);

void execute_and(int *status, char **command, env_node_t *env, int *exec);

void execute_or(int *status, char **command, env_node_t *env, int *exec);

void free_mem(env_node_t *env, char **split, char **args);

#endif /* !MINISHELL_H_ */
