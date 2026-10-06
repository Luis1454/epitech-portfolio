/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** get_fonction_name
*/

#include "../include/get_fonction_name.h"

char *recup_lib(FILE *file, unsigned long long addr)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    lib_t lib;

    read = getline(&line, &len, file);
    while (read != -1) {
        sscanf(line, "%llx-%llx %4s %llx %x:%x %d %s\n",
        &lib.start, &lib.end, lib.perms, &lib.offset,
        &lib.dev_major, &lib.dev_minor, &lib.inode, lib.pathname);
        if (addr >= lib.start && addr <= lib.end) {
            fclose(file);
            free(line);
            return strdup(lib.pathname);
        }
        read = getline(&line, &len, file);
    }
    fclose(file);
    free(line);
    return NULL;
}

char *get_adress_in_symbol(ftrace_t *ftrace, unsigned long long addr)
{
    char *path = malloc(1024);
    FILE *file;

    sprintf(path, "/proc/%d/maps", ftrace->pid);
    file = fopen(path, "r");
    if (!file) {
        perror("fopen");
        return NULL;
    }
    return recup_lib(file, addr);
}

static char *recup_the_name(ftrace_t *ftrace, unsigned long long addr)
{
    char *name = NULL;

    ftrace->elf.scn = elf_nextscn(ftrace->elf.elf, ftrace->elf.scn);
    for (; ftrace->elf.scn != NULL;
    ftrace->elf.scn = elf_nextscn(ftrace->elf.elf, ftrace->elf.scn)) {
        gelf_getshdr(ftrace->elf.scn, &ftrace->elf.shdr);
        if (ftrace->elf.shdr.sh_type != SHT_SYMTAB)
            continue;
        ftrace->elf.data = elf_getdata(ftrace->elf.scn, NULL);
        if (ftrace->elf.data == NULL)
            return NULL;
        name = get_adress_in_symbol(ftrace, addr);
    }
    return name;
}

char *get_function_name(ftrace_t *ftrace, unsigned long long addr)
{
    ftrace->elf.scn = NULL;
    ftrace->elf.data = NULL;
    ftrace->elf.elf = elf_begin(ftrace->elf.fd, ELF_C_READ, NULL);
    if (!ftrace->elf.elf) {
        perror("elf_begin");
        return NULL;
    }
    return recup_the_name(ftrace, addr);
}
