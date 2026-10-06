/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** error_message
*/

#include "../include/error.h"

int display_help(void)
{
    printf("USAGE: ./ftrace <command>\n");
    exit(0);
    return 0;
}

int fonction_perror(char *str)
{
    perror(str);
    return 84;
}

int fonction_write_error(char *str)
{
    write(2, str, strlen(str));
    return 84;
}
