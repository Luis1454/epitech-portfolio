/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** parsing_file.c
*/

#include "lib.h"

int get_size_file(int fd)
{
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    return size;
}

char *my_strrchr(char *str, char c)
{
    int i = 0;
    int j = 0;
    char *res = NULL;
    while (str[i] != '\0') {
        if (str[i] == c) {
            res = &str[i];
            j++;
        }
        i++;
    }
    if (j == 0)
        return NULL;
    return res;
}

int verify_extension(char *filename, char *extension)
{
    char *ext = my_strrchr(filename, '.');
    if (ext == NULL || strcmp(ext, extension) != 0)
        return 1;
    return 0;
}

int check_directory(char *filename, int fd)
{
    fd = open(filename, O_RDONLY | __O_DIRECTORY);
    if (fd != -1) {
        close(fd);
        my_putstr_error("Error: ");
        my_putstr_error(filename);
        my_putstr_error(" is not a file\n");
        return 1;
    }
    return 0;
}

char *open_file(char *filename, int *file_size)
{
    char *file_contents;
    int fd = 0;

    check_directory(filename, fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;
    *file_size = get_size_file(fd);
    file_contents = (char*)malloc(*file_size * sizeof(char));
    read(fd, file_contents, *file_size);
    close(fd);
    return file_contents;
}
