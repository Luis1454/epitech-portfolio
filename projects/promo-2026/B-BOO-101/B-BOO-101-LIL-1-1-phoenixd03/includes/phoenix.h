/*
** EPITECH PROJECT, 2021
** phoenix.h
** File description:
** phoenix includes
*/

#ifndef __PHOENIX_H__
#define __PHOENIX_H__

void my_putchar(char c);

int show_number(int nb);

int show_string(char const *str);

char *reverse_string(char *str);

int to_number(char const *str);

int is_prime_number(int nb);

char *my_strcpy(char *dest, char const *src);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find);

int get_nb_len(int nb);

int my_strlen(char *str);

int iterative_factorial(int nb);

int min(int a, int b);

int max(int a, int b);

char *my_strlowcase(char *str);

char *my_strupcase(char *str);

int recursive_power(int nb, int p);

int show_alphabet(void);

int print_nbr(int nbr, int p);

int pwr(int nb);

int show_combinations(void);

#endif /* __PHOENIX_H__ */
