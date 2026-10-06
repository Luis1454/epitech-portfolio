/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** lib.h
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

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
    char **my_strtoword_array(char const *str, char delim_char);
    char **my_strtoword_array_muldelim(char const *str, ...);
    int my_str_isalphanum(const char *str);
    void putchar_error(char c);
    int my_putstr_error(char const *str);
    char *my_strdup(char *src);
    char **my_array_remove_char(char **array, char c);
    int my_array_size(char **array);
    int my_str_contain_char(char *str, char *c);
    char *replace_char(char *line, char d, char r);
    char **my_deplace_array(char **array);
    char *my_clean_str(char *src);
    int my_str_isnum(char const *str);
    int my_pow(int nb, int p);
    int my_getnbr(char const *str);
    char *my_metset(char *str, char c, int size);
    char *my_c_clean_str(char *src, char c);
/*-----*/

#endif
