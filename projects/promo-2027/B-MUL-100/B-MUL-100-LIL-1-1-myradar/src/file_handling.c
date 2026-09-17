/*
** EPITECH PROJECT, 2022
** file_handling.c
** File description:
** file handling functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_extention(const char *path, const char *ext)
{
    int i = 0;
    int j = 0;

    for (; path[i]; i++);
    for (; path[i] != '.' && i >= 0; i--);
    if (i < 0)
        return 0;
    for (i++; path[i] && ext[j] && path[i] == ext[j]; i++, j++);
    return path[i] == ext[j];
}

void print_open_error(const char *path)
{
    my_print_error("Error: could not open \"");
    my_print_error(path);
    my_print_error("\"\n");
    my_print_error("Make sure the file exists and is readable\n");
}

static int sub_open_file(const char *path, int fd, int state)
{
    if (state && !check_extention(path, "RDR")
    && !check_extention(path, "rdr")) {
        my_print_error("Error: the file \"");
        my_print_error(path);
        my_print_error("\" is not a .rdr file\n");
        return 1;
    }
    if (fd == -1) {
        print_open_error(path);
        return 1;
    }
    return 0;
}

char *open_file(const char *path, int state)
{
    char *buffer;
    int fd = open(path, O_RDONLY);
    int size;

    if (sub_open_file(path, fd, state))
        return NULL;
    if ((buffer = malloc(sizeof(char) * 350000)) == NULL) {
        my_print_error("Error: could not allocate memory for the buffer\n");
        close(fd);
        return NULL;
    }
    size = read(fd, buffer, 350000);
    buffer[size] = 0;
    close(fd);
    return buffer;
}

int display_file(const char *path)
{
    char *buffer = open_file(path, 0);

    if (buffer == NULL)
        return 84;
    my_putstr(buffer);
    free(buffer);
    return 0;
}
