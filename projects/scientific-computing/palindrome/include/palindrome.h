/*
** EPITECH PROJECT, 2023
** palindrome.h
** File description:
** palindrome includes
*/

#ifndef PALINDROME_H_
    #define PALINDROME_H_

    typedef struct core {
        int n;
        int p;
        int b;
        int i;
        int out;
        int imin;
        int imax;
    } core_t;

int check_args(int ac, char * const *av);

int get_rev_int(int nb, int base);

int check_values(core_t *core);

int get_base_len(int nb, int base);

core_t *init_core(int ac, char * const *av);

int display_help(void);

#endif /* !PALINDROME_H_ */
