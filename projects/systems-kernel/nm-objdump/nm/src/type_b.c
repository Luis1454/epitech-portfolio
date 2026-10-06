/*
** EPITECH PROJECT, 2024
** type_b.c
** File description:
** types
*/

#include "../include/flags.h"
#include "../include/my_nm.h"

int is_aa(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return sym.st_shndx == SHN_ABS;
}

int is_cc(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return sym.st_shndx == SHN_COMMON;
}

int is_b(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_LOCAL
        && shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags & SHF_ALLOC
        && shdr[sym.st_shndx].sh_flags & SHF_WRITE;
}

int is_bb(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_GLOBAL
        && shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags & SHF_ALLOC
        && shdr[sym.st_shndx].sh_flags & SHF_WRITE;
}

int is_rr(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return shdr[sym.st_shndx].sh_type == SHT_PROGBITS
    && shdr[sym.st_shndx].sh_flags == SHF_ALLOC;
}
