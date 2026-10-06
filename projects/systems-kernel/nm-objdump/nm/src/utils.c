/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils
*/

#include "../include/flags.h"
#include "../include/my_nm.h"

int error_handler(char *path, char *exec)
{
    int code = errno;
    struct stat s;

    if (stat(path, &s)) {
        dprintf(2, "%s: '%s': %s\n", exec, path, "No such file");
        return 84;
    }
    if (S_ISDIR(s.st_mode)) {
        dprintf(2, "%s: Warning: '%s' is a directory\n", exec, path);
        return 84;
    }
    if (code == EINVAL)
        return 84;
    dprintf(2, "%s: %s: %s\n", exec, path, strerror(code));
    return 84;
}

static type_t *get_types(type_t *types)
{
    types[0] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_u, 'u'};
    types[1] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_ww, 'W'};
    types[2] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_w, 'w'};
    types[3] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_v, 'v'};
    types[4] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_uu, 'U'};
    types[5] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_aa, 'A'};
    types[6] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_cc, 'C'};
    types[7] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_b, 'b'};
    types[8] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_bb, 'B'};
    types[9] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_r, 'r'};
    types[10] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_rr, 'R'};
    types[11] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_t, 't'};
    types[12] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_tt, 'T'};
    types[13] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_dd, 'D'};
    types[14] = (type_t){(int (*)(Elf64_Sym, Elf64_Shdr *))is_d, 'd'};
    types[15] = (type_t){NULL, 0};
    return types;
}

char get_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    int i = 0;
    char c = 0;
    type_t *types = malloc(sizeof(type_t) * 16);

    types = get_types(types);
    for (i = 0; types[i].is_type; i++)
        if (types[i].is_type(sym, shdr)) {
            c = types[i].c;
            free(types);
            return c;
        }
    free(types);
    return 'd';
}
