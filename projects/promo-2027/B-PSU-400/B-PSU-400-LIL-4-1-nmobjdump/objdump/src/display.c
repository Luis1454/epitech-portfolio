/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** display
*/

#include "../include/flags.h"
#include "../include/my_objdump.h"

void display_flags(Elf64_Ehdr *header)
{
    int first = 1;
    unsigned int flags = get_flags(header);
    flag_t flags_list[] = {
        (flag_t){HAS_RELOC, "HAS_RELOC"},
        (flag_t){EXEC_P, "EXEC_P"},
        (flag_t){HAS_LINENO, "HAS_LINENO"},
        (flag_t){HAS_DEBUG, "HAS_DEBUG"},
        (flag_t){HAS_SYMS, "HAS_SYMS"},
        (flag_t){HAS_LOCALS, "HAS_LOCALS"},
        (flag_t){DYNAMIC, "DYNAMIC"},
        (flag_t){WP_TEXT, "WP_TEXT"},
        (flag_t){D_PAGED, "D_PAGED"}
    };

    for (int i = 0; i < 9; i++)
        if (flags & flags_list[i].flag) {
            printf("%s%s", (first ? "" : ", "), flags_list[i].name);
            first = 0;
        }
    printf("\n");
}

void display_header(Elf64_Ehdr *header, char *path)
{
    printf("\n%s:     file format elf64-x86-64\n",
    &path[strchr("/~#", *path) ? 0 : 2]);
    printf("architecture: %s, flags 0x%08x:\n",
    get_arch(header->e_machine), get_flags(header));
    display_flags(header);
    printf("start address 0x%016lx\n\n", header->e_entry);
}

void display_id(int size, int offset, int i)
{
    if (size <= 0xffff) {
        printf(" %04x ", offset + i);
        return;
    } else if (size <= 0xfffff) {
        printf(" %05x ", offset + i);
        return;
    }
    if (size <= 0xfffffff) {
        printf(" %06x ", offset + i);
        return;
    } else
        printf(" %07x ", offset + i);
}

void display_memory(char *str, int size, int offset)
{
    for (int i = 0; i < size; i++) {
        if (i % 4 == 0 && i % 16 != 0)
            printf(i ? " " : "");
        if (i % 16 == 0 && i)
            show_ascii(str, i - 16, 16);
        if (i % 16 == 0)
            display_id(size, offset, i);
        printf("%02x", (unsigned char)str[i]);
    }
    if (!(size % 16)) {
        show_ascii(str, size >= 16 ? size - 16 : 0, 16);
        return;
    }
    for (int i = size % 16; i < 16; i++) {
        if (!(i % 4) && i)
            printf(" ");
        printf("  ");
    }
    show_ascii(str, size - (size % 16), size % 16);
}

void display_sections(void *data, Elf64_Ehdr *header)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)(data + header->e_shoff);
    Elf64_Shdr *sec = NULL;
    char *name = NULL;

    for (int i = 0; i < header->e_shnum; i++) {
        sec = &sections[i];
        name = (char *)(data +
        sections[header->e_shstrndx].sh_offset + sec->sh_name);
        if (sec->sh_size && strlen(name) && is_sec_allowed(name)) {
            printf("Contents of section %s:\n", name);
            display_memory((char *)(data + sec->sh_offset),
            sec->sh_size, sec->sh_addr);
        }
    }
}
