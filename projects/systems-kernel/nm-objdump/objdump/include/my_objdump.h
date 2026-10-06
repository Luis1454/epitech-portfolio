/*
** EPITECH PROJECT, 2024
** my_objdump.h
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
    #define MY_OBJDUMP_H_

    #include <dlfcn.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <math.h>
    #include <elf.h>
    #include <sys/mman.h>
    #include <sys/utsname.h>

unsigned int get_flags(Elf64_Ehdr *elf);

char *get_arch(int machine);

void show_ascii(char *str, int i, int size);

void display_header(Elf64_Ehdr *header, char *path);

void display_sections(void *data, Elf64_Ehdr *header);

int is_sec_allowed(char *name);

char *path_handler(char *filename);

typedef struct flag_s {
    unsigned int flag;
    char *name;
} flag_t;

#endif /* !MY_OBJDUMP_H_ */
