/*
** EPITECH PROJECT, 2021
** minishell.c
** File description:
** init file for minishell2
*/

#include "../includes/my.h"
#include "../includes/minishell.h"

char *parse_str(char *str, char A, char B, int i)
{
    char *out = malloc(sizeof(char) * my_strlen(str));
    int j = 0;

    for (; str[i] != A; i++);
    for (; str[i + j] != B; j++)
        out[j] = str[i + j];
    out[j] = 0;
    return out;
}

char *get_value(Env *env, char *var)
{
    Node *tmp = env->head;

    tmp = tmp->next;
    for (; tmp->next != NULL && !are_equals(tmp->var, var); tmp = tmp->next);
    return tmp->val;
}

void get_folder(Env *env, char *str)
{
    int i = my_strlen(str);
    int j = 0;
    if (my_strlen(str) > 1) {
        for (; i && str[i] != '/'; i--);
        env->folder = malloc(sizeof(char) * (my_strlen(str) - i + 2));
        i++;
        for (; str[i + j]; j++)
            env->folder[j] = str[i + j];
        env->folder[j] = 0;
    } else {
        env->folder = malloc(sizeof(char) * (my_strlen(str) + 1));
        env->folder[my_strlen(str)] = 0;
        env->folder = str;
    }
}

void get_prompt(Env *env)
{
    get_folder(env, get_value(env, "PWD"));
    if (are_equals(get_value(env, "HOME"), get_value(env, "PWD")))
        env->folder = "~";
    env->prompt = malloc(sizeof(char) * (my_strlen(get_value(env, "USER"))
    + my_strlen(get_value(env, "HOSTNAME")) + my_strlen(env->folder) + 7));
    my_strcpy(env->prompt, "[");
    my_strcat(env->prompt, get_value(env, "USER"));
    my_strcat(env->prompt, "@");
    my_strcat(env->prompt, get_value(env, "HOSTNAME"));
    my_strcat(env->prompt, " ");
    my_strcat(env->prompt, env->folder);
    my_strcat(env->prompt, "]$ ");
}

void init_env(Env *env, char **arr)
{
    int len = 0;
    int i;

    env->shell = "mysh";
    for (; arr[len]; len++);
    env->cmd = malloc(sizeof(char *) * 20);
    for (i = 0; i < 20; i++)
        env->cmd[i] = malloc(sizeof(char) * 100);
    env->folder = malloc(sizeof(char) * 1024);
    env->head = malloc(sizeof(Node));
    env->len = len;
    env->arr = malloc(sizeof(char *) * (len + 1));
    for (i = 0; i < len; i++) {
        env->arr[i] = malloc(sizeof(char) * my_strlen(arr[i]));
        env->arr[i] = arr[i];
    }
    env->arr[i] = NULL;
    my_getenv(env);
}
