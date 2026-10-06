/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** error
*/

#ifndef ERROR_H_
    #define ERROR_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>

int display_help(void);
int fonction_perror(char *str);
int fonction_write_error(char *str);

#endif /* !ERROR_H_ */
