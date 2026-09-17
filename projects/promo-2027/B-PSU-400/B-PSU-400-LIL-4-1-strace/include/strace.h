/*
** EPITECH PROJECT, 2022
** strace.h
** File description:
** strace includes
*/

#ifndef MY_ERR_
    #define MY_ERR_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/ptrace.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <errno.h>

    #define PATH_MAX 4096
    #define ERROR_CODE 84

typedef struct syscall_s {
    int id;
    char *name;
    int nb_args;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    int arg5;
    int arg6;
    int arg7;
} syscall_t;

typedef struct args_s {
    int arg_s;
    int arg_p;
    int size;
    int pid;
    int state;
    char **av;
} args_t;

typedef struct user_regs_struct reg_t;

char *getpath(const char **env);

int get_nb_vars(const char **env);

void display_args(reg_t args, syscall_t info, args_t cmd);

int handle_cmd_failure(reg_t regs);

int get_args(int argc, char *argv[], args_t *args);

#endif /* MY_ERR_ */
