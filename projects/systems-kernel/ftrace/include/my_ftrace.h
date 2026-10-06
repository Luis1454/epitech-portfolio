/*
** EPITECH PROJECT, 2023
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** my_ftrace.h
*/

#ifndef MY_FTRACE_H_
    #define MY_FTRACE_H_

    #include <elf.h>
    #include <gelf.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/ptrace.h>

    #define ENTERING_FUNCTION "Entering function %s at 0x%llx\n"
    #define LEAVING_FUNCTION "Leaving function %s\n"

typedef struct s_elf {
    GElf_Shdr section_header;
    GElf_Ehdr elf_header;
    Elf_Scn *section;
    Elf_Scn *strtab_section;
    GElf_Shdr shdr;
    char *strtab;
    size_t strtab_size;
    char *filename;
    uint32_t addr;
    char *result;
    Elf *elf;
    int end;
    int fd;
    Elf_Scn *scn;
    Elf_Data *data;
    GElf_Sym sym;
} elf_t;

typedef struct s_ftrace {
    pid_t pid;
    char *binary_name;
    int status;
    struct user_regs_struct regs;
    elf_t elf;
} ftrace_t;

#endif /* MY_FTRACE_H_ */
