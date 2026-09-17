/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for nm
*/

#include "../include/my_nm.h"
#include "../include/flags.h"

int compare(const char *s1, const char *s2, const char *ignored)
{
    int i = 0;
    int a = 0;
    int b = 0;

    for (; s1[i + a] && s2[i + b]; i++) {
        while (s1[i + a] && strchr(ignored, tolower(s1[i + a])))
            a++;
        while (s2[i + b] && strchr(ignored, tolower(s2[i + b])))
            b++;
        if (tolower(s1[i + a]) != tolower(s2[i + b]))
            return tolower(s1[i + a]) - tolower(s2[i + b]);
    }
    if (s1[i + a])
        return 1;
    if (s2[i + b])
        return -1;
    return 0;
}

int sub_nm(char *filename, void *data, int ac, int fd)
{
    Elf64_Ehdr *h = (Elf64_Ehdr *)data;
    struct stat s;

    fstat(fd, &s);
    if (h->e_ident[EI_MAG0] != ELFMAG0 || h->e_ident[EI_MAG1] != ELFMAG1
    || h->e_ident[EI_MAG2] != ELFMAG2 || h->e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(2, "nm: %s: file format not recognized\n", filename);
        return 84;
    }
    if (ac > 2)
        printf("\n%s:\n", filename);
    if (!display_symbols(data, h)) {
        dprintf(2, "nm: %s: no symbols\n", filename);
        return 84;
    }
    munmap(data, s.st_size);
    close(fd);
    return 0;
}

int my_nm(char *filename, int ac)
{
    int fd = open(filename, O_RDONLY);
    struct stat s;
    void *data;

    if (fd == -1)
        return error_handler(filename, "nm");
    fstat(fd, &s);
    data = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED)
        return error_handler(filename, "nm");
    return sub_nm(filename, data, ac, fd);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (my_nm("a.out", 1));
    for (int i = 1; i < ac; i++)
        my_nm(av[i], ac);
    return 0;
}
