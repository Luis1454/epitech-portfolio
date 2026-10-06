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

int exec(int *fd, pid_t pid, char **cmd1, char **cmd2)
{
    pid_t pid2;

    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        execvp(cmd1[0], cmd1);
        perror("Erreur lors de la première commande");
        return (-1);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            close(fd[1]);
            dup2(fd[0], 0);
            execvp(cmd2[0], cmd2);
            perror("Erreur de la deuxième commande");
            return (0);
        }
        waitpid(pid, NULL, 0);
    }
    return (0);
}

int exec_pipe(char **cmd1, char **cmd2)
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Erreur lors de la création du pipe");
        return -1;
    }
    pid = fork();
    if (pid < 0) {
        perror("Erreur lors de la création du processus");
        return -1;
    }
    if (exec(fd, pid, cmd1, cmd2) == -1)
        return (-1);
    return (0);
}

int hall_pipe(char **tab, char **cmd2, int *tb)
{
    int nb = 0;

    for (tb[1] = tb[0] + 1; tab[tb[1]]; tb[1]++) {
        cmd2[tb[3]] = my_strdup(tab[tb[1]]);
        tb[3]++;
    }
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '|') {
            nb = i;
            break;
        }
    }
    cmd2[tb[3]] = '\0';
    tab[nb] = '\0';
    exec_pipe(tab, cmd2);
    return (0);
}

int check_error_pipe(char **tab)
{
    if (tab[0] && tab[0][0] == '|') {
        perror("Invalid null command.");
        return (-1);
    }
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '|' && tab[i + 1][0] == '\0') {
            perror("Invalid null command.");
            return (-1);
        }
    }
    return (0);
}

int do_pipes(env_node_t *env, char **tab, int *status)
{
    char **cmd2 = malloc(sizeof(char *) * my_arrlen(tab));
    int tb[4] = {0, 0, 0, 0};

    for (; tab[tb[0]]; tb[0]++) {
        if (tab[tb[0]][0] == '|') {
            tb[2]++;
            break;
        }
    }
    if (tb[2] == 0) {
        *status = handling(tab, env, *status);
    } else {
        hall_pipe(tab, cmd2, tb);
    }
    return (*status);
}
