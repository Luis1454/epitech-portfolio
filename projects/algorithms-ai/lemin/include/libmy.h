/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** dsk
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef LIBMY_H_
    #define LIBMY_H_
    typedef enum {
        STRING,
        STRING_ARRAY
    } ArgumentType;
    void my_free(int count, ...);
    int flag_i (va_list ap);
    int flag_d (va_list ap);
    int flag_s (va_list ap);
    int flag_c (va_list ap);
    int flag_u (va_list ap);
    int flag_o (va_list ap);
    int flag_pourcent (va_list ap);
    int flag_x (va_list ap);
    int flag_xx (va_list ap);
    int flag_f (va_list ap);
    int flag_e (va_list ap);
    int flag_ee (va_list ap);
    int flag_p (va_list ap);
    int flag_b (va_list ap);
    int my_abs(int nb);
    int my_array_len(char **arr);
    int my_atoi(char const *str);
    int my_binary_converter(int nb);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    void my_free_array(char **array);
    int my_getnbr(char const *str);
    char *my_hexadecimal_converter(int nb, int maj);
    int my_is_prime(int nb);
    void my_isneg(int n);
    char *my_itoa(int nb);
    char **my_malloc_array(int nb_rows, int nb_cols);
    int my_nbrlen(int nb);
    int my_octal_converter(int nb);
    double my_pow(double nb, int p);
    void my_print_array(char **array);
    int my_printf(const char *typ_flag , ...);
    void my_putadress(void *adress);
    void my_putchar(char c);
    void my_putfloat(double n, int prec);
    int my_putnbr_base(long nb, char const *base);
    void my_putnbr(int nb);
    void my_putstr(char const *str);
    char *my_revstr(char *str);
    int my_scientifique_converter(double nb, int maj);
    double my_sqrt(double n);
    int my_str_is_numb(char *str);
    char **my_str_to_word_array(char const *str, char c);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
    char *my_strncat(char *dest, char *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strndup(char const *src, int n);
    char *my_strstr(char *str, char *to_find);
    int my_swap(int *a, int *b);
    int my_str_is_alpha(char *str);
#endif /* !LIBMY_H_ */
