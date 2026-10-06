/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** get_fonction_name
*/

#ifndef GET_FONCTION_NAME_H_
    #define GET_FONCTION_NAME_H_

    #include "my_ftrace.h"

typedef struct s_lib {
    unsigned long long start;
    unsigned long long end;
    char perms[5];
    unsigned long long offset;
    int dev_major;
    int dev_minor;
    int inode;
    char pathname[1024];
} lib_t;

char *get_function_name(ftrace_t *ftrace, unsigned long long addr);

#endif /* !GET_FONCTION_NAME_H_ */
