/*
** EPITECH PROJECT, 2024
** my_nm.h
** File description:
** my_nm
*/

#ifndef MY_NM_H_
    #define MY_NM_H_

    #include <dlfcn.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <elf.h>
    #include <sys/mman.h>
    #include <sys/utsname.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <ctype.h>

typedef struct type_s {
    int (*is_type)(Elf64_Sym sym, Elf64_Shdr *shdr);
    char c;
} type_t;

typedef struct sym_s {
    char *name;
    char type;
    unsigned long value;
    struct sym_s *next;
    struct sym_s *prev;
} sym_t;

int error_handler(char *path, char *exec);
char get_type(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_u(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_w(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_ww(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_v(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_uu(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_aa(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_cc(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_b(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_bb(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_r(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_rr(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_t(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_tt(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_dd(Elf64_Sym sym, Elf64_Shdr *shdr);
int is_d(Elf64_Sym sym, Elf64_Shdr *shdr);

void add_node(sym_t **arr, sym_t node);

void sort_symbols(sym_t **arr);

int display_symbols(void *data, Elf64_Ehdr *header);

int compare(const char *s1, const char *s2, const char *ignored);

#endif /* !MY_NM_H_ */
