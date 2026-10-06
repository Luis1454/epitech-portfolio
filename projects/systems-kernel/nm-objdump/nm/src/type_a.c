/*
** EPITECH PROJECT, 2024
** type_a.c
** File description:
** types
*/

#include "../include/flags.h"
#include "../include/my_nm.h"

int is_u(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE;
}

int is_w(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_WEAK
    && ELF64_ST_TYPE(sym.st_info) != STT_OBJECT
    && shdr[sym.st_shndx].sh_type != SHT_NOBITS;
}

int is_ww(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return ELF64_ST_BIND(sym.st_info) == STB_WEAK
    && ELF64_ST_TYPE(sym.st_info) != STT_OBJECT;
}

int is_v(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return ELF64_ST_BIND(sym.st_info) == STB_WEAK
    && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT
    && sym.st_shndx == SHN_UNDEF;
}

int is_uu(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    (void)shdr;
    return sym.st_shndx == SHN_UNDEF;
}
