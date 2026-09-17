/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** display
*/

#include "../include/flags.h"
#include "../include/my_nm.h"

static void sub_a(Elf64_Shdr *shdr, void *data, sym_t **arr, int i)
{
    Elf64_Sym *symtab = (Elf64_Sym *)(data + shdr[i].sh_offset);
    sym_t sym = {0};
    char *name = NULL;

    for (unsigned int j = 0; j < shdr[i].sh_size / sizeof(Elf64_Sym); j++) {
        name = (char *)(data + shdr[shdr[i].sh_link].sh_offset +
        symtab[j].st_name);
        if (name[0]) {
            sym.name = name;
            sym.type = get_type(symtab[j], shdr);
            sym.value = symtab[j].st_value;
            add_node(arr, sym);
        }
    }
}

static void sub_b(sym_t *arr)
{
    sort_symbols(&arr);
    for (sym_t *tmp = arr; tmp; tmp = tmp->next) {
        if (tmp->type == 'A')
            continue;
        if (tmp->type == 'U' || tmp->type == 'w' || tmp->type == 'v')
            printf("%16c %c %s\n", ' ', tmp->type, tmp->name);
        else
            printf("%016lx %c %s\n", tmp->value, tmp->type, tmp->name);
    }
}

int display_symbols(void *data, Elf64_Ehdr *header)
{
    Elf64_Shdr *shdr = (Elf64_Shdr *)(data + header->e_shoff);
    sym_t *arr = NULL;
    int nb_sym = 0;

    for (int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            nb_sym++;
            sub_a(shdr, data, &arr, i);
            sub_b(arr);
        }
    }
    return nb_sym;
}
