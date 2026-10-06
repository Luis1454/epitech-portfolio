/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** lib.h
*/

#include "base.h"
#include "corewar.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#ifndef LIB_H
    #define LIB_H

/* LIB */
    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int my_printf(const char *format, ...);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_memset(char *str, char c, int size);
    int my_str_isalphanum(const char *str);
    void putchar_error(char c);
    int my_putstr_error(char const *str);
    char *my_strdup(char const *src);
    char *my_strstr(char *str, char const *to_find);
    char *my_revstr(char *str);
    int my_getnbr(char const *str, char delim);
    char *my_strcat(char *dest, char const *src);
    int my_str_isnum(char const *str);
    int my_strnlen(char const *str, int n);
/*-----*/

/* COMMAND */
    int find_cmd(char *buffer, int fd);
    int live(char **command, int fd);
    int ld_c(char **command, int fd);
    int st_c(char **command, int fd);
    int add(char **command, int fd);
    int sub(char **command, int fd);
    int and_c(char **command, int fd);
    int or_c(char **command, int fd);
    int xor_c(char **command, int fd);
    int zjmp(char **command, int fd);
    int ldi(char **command, int fd);
    int sti(char **command, int fd);
    int fork_a(char **command, int fd);
    int lld(char **command, int fd);
    int lldi(char **command, int fd);
    int lfork(char **command, int fd);
    int aff(char **command, int fd);
/*---------*/

/* PARSER */
    int parse_file(char *buffer, int len);
/*--------*/

#endif
