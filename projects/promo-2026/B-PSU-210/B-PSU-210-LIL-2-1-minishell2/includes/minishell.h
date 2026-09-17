/*
** EPITECH PROJECT, 2021
** include.h
** File description:
** custom graphical include
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct table {
    char **var;
    char **value;
} Table;

typedef struct node {
    struct node *post;
    struct node *next;
    char *var;
    char *val;
} Node;

typedef struct env {
    Node *first;
    Node *head;
    char **arr;
    char *shell;
    int len;
    int last_return;
    char *prompt;
    char **hist;
    int hist_len;
    int state;
    char *folder;
    char **cmd;
} Env;

void my_env(Env *env);

int my_echo(Env *env);

void my_getenv(Env *env);

char *get_value(Env *env, char *str);

int check_cd(Env *env);

void my_cleanstr(char *str);

int edit_node(Env *env, char *var, char *val);

int add_node(Env *env, char *var, char *val);

int init_node(Env *env, char *var, char *val);

void read_array(char **arr);

char *parse_str(char *str, char A, char B, int i);

void get_prompt(Env *env);

int get_cmd(Env *env, char *buf);

void init_env(Env *env, char **arr);

int my_setenv(Env *env, char *var, char *val, int nb);

int my_unsetenv(Env *env, char *var);

void print_error(Env *env, char *cmd, char *msg, char *end);

void check_args(Env *env);

int check_setenv(Env *env);

int check_unsetenv(Env *env);

int print_ll_str(Node *node);

int var_exist(Env *env, char *var);

#endif /* INCLUDE_H_ */
