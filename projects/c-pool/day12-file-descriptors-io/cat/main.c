/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "../include/my.h"
#include "../include/handling.h"
#include "../include/mylist.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void reset_buffer(char *buf, int size)
{
    for (int i = 0; i < size; i++)
        buf[i] = 0;
}

void show_error(int err, char *arg)
{
    my_print_error("cat: ");
    my_print_error(arg);
    my_print_error(": ");
    my_print_errno(err);
    my_print_error("\n");   
}

int get_files(int argc, char * const *argv)
{
    int i;
    int fd = 0;
    int size = 0;
    int tmp = argc;
    char buf[30000];

    for (i = 1; i < argc; i++, fd = 0) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
            show_error(errno, argv[i]);
        else {
            size = read(fd, &buf, 30000);
            buf[size] = 0;
            my_putstr(buf);
            close(fd);
        }
    }
    return 0;
}

int main(int argc, char * const *argv)
{
    char buf[30000];
    int state;

    if (argc > 1) {
        state = get_files(argc, argv);
        if (state)
            return 84;
    } else
        while (1) {
            reset_buffer(buf, 30000);
            read(1, &buf, 30000);
            my_putstr(buf);
        }
    return 0;
}
