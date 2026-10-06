/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** fonction_gestion
*/

#ifndef FONCTION_GESTION_H_
    #define FONCTION_GESTION_H_

    #include "my_ftrace.h"
    #include "get_fonction_name.h"
    #define OP_CODE 0xe8

int fonction_manager(ftrace_t *ftrace, unsigned long long *previous_addr);
int open_and_verif(ftrace_t *ftrace, char *filename);

#endif /* !FONCTION_GESTION_H_ */
