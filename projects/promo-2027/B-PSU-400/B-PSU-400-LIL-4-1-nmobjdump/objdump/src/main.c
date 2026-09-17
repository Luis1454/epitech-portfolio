/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** my_objdump main
*/

#include "../include/flags.h"
#include "../include/my_objdump.h"
#include <errno.h>

int error_handler(char *path, char *exec)
{
    int code = errno;
    struct stat s;

    path = *path == '/' ? path : path + 2;
    if (stat(path, &s)) {
        dprintf(2, "%s: '%s': %s\n", exec, path, "No such file");
        return 84;
    } else if (S_ISDIR(s.st_mode)) {
        dprintf(2, "%s: Warning: '%s' is a directory\n", exec, path);
        return 84;
    }
    if (code == EINVAL)
        return 84;
    dprintf(2, "%s: %s: %s\n", exec, path, strerror(code));
    return 84;
}

int handling(char *path, void *data)
{
    Elf64_Ehdr *header = (Elf64_Ehdr *)data;

    if (header->e_ident[EI_MAG0] != ELFMAG0
    || header->e_ident[EI_MAG1] != ELFMAG1
    || header->e_ident[EI_MAG2] != ELFMAG2
    || header->e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(2, "objdump: %s: file format not recognized\n", path);
        return 1;
    }
    display_header(header, path);
    display_sections(data, header);
    return 0;
}

int get_datas(char *path)
{
    struct stat s;
    void *data = NULL;
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return error_handler(path, "objdump");
    if (stat(path, &s) == -1)
        return 84;
    if (S_ISDIR(s.st_mode)) {
        dprintf(2, "objdump: Warning: '%s' is a directory\n",
        *path == '/' ? path : path + 2);
        return 84;
    }
    data = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED)
        return 84;
    if (handling(path, data))
        return 84;
    return 0;
}

int my_objdump(char *filename)
{
    char *path = path_handler(filename);

    if (!path)
        return 84;
    return get_datas(path);
}

int main(int ac, char **av)
{
    if (ac == 2)
        return my_objdump(av[1]);
    return 84;
}
