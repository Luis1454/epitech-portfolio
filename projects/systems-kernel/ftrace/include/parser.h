/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** parser
*/

#ifndef PARSER_H_
    #define PARSER_H_

    #include "error.h"
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <elf.h>

int parser(int ac, char **av);

#endif /* !PARSER_H_ */
