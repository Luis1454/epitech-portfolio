/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils
*/

#include "../include/flags.h"
#include "../include/my_objdump.h"

unsigned int get_flags(Elf64_Ehdr *elf)
{
    unsigned int flags = BFD_NO_FLAGS;

    flags += elf->e_type == ET_REL ? HAS_RELOC : 0;
    flags += elf->e_type == ET_EXEC ? EXEC_P : 0;
    flags += elf->e_type == ET_DYN ? DYNAMIC : 0;
    flags += (elf->e_type == ET_EXEC || elf->e_type == ET_DYN) ? D_PAGED : 0;
    flags += (elf->e_type == ET_EXEC || elf->e_type == ET_DYN
    || elf->e_type == ET_REL) ? HAS_SYMS : 0;
    return flags;
}

int is_sec_allowed(char *name)
{
    char *forbidden[] = {".bss", ".shstrtab", ".symtab", ".strtab",
    ".tbss", ".tdata", ".rela.text", ".rela.eh_frame", ".rela.rodata", NULL};

    for (int i = 0; forbidden[i]; i++)
        if (!strcmp(name, forbidden[i]))
            return 0;
    return 1;
}

void show_ascii(char *str, int i, int size)
{
    printf("  ");
    for (int j = 0; j < size; j++)
        if (str[i + j] >= 32 && str[i + j] <= 126)
            printf("%c", str[i + j]);
        else
            printf(".");
    for (int j = 0; j < 16 - size; j++)
        printf(" ");
    printf("\n");
}

char *path_handler(char *filename)
{
    char *path = malloc(sizeof(char) * strlen(filename) + 3);

    if (!path)
        return NULL;
    if (!strchr("/~#", *filename))
        strcpy(path, "./");
    strcat(path, filename);
    return path;
}

char *get_arch(int machine)
{
    switch (machine) {
        case EM_X86_64:
            return "i386:x86-64";
        case EM_386:
            return "i386";
        case EM_ARM:
            return "arm";
        case EM_AARCH64:
            return "aarch64";
        default:
            return "unknown";
    }
}
