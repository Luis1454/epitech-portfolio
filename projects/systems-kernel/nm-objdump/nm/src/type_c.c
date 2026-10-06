/*
** EPITECH PROJECT, 2024
** type_c.c
** File description:
** types
*/

#include "../include/flags.h"
#include "../include/my_nm.h"

int is_tt(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return shdr[sym.st_shndx].sh_type == SHT_PROGBITS
    && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR);
}

int is_t(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return shdr[sym.st_shndx].sh_type == SHT_PROGBITS
    && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)
    && ELF64_ST_BIND(sym.st_info) == STB_LOCAL;
}

int is_r(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_LOCAL
    && shdr[sym.st_shndx].sh_type != SHT_NOBITS
    && shdr[sym.st_shndx].sh_flags == SHF_ALLOC;
}

int is_d(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_LOCAL
    && shdr[sym.st_shndx].sh_type == SHT_PROGBITS
    && shdr[sym.st_shndx].sh_flags & SHF_ALLOC
    && shdr[sym.st_shndx].sh_flags & SHF_WRITE;
}

int is_dd(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    return ELF64_ST_BIND(sym.st_info) == STB_GLOBAL
    && shdr[sym.st_shndx].sh_type == SHT_PROGBITS
    && shdr[sym.st_shndx].sh_flags & SHF_ALLOC
    && shdr[sym.st_shndx].sh_flags & SHF_WRITE;
}
