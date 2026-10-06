/*
** EPITECH PROJECT, 2021
** sub_main.c
** File description:
** my own ls function
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/mylist.h"

void sub_handle_core(char *argv[], int *args, int *tab, int n)
{
    int argc = 0;
    read_list_t *head = NULL;

    for (; argv[argc]; argc++);
    for (int i = 1; i < argc; i++) {
        head = init_file(argv[i]);
        if (args[i] && head != NULL) {
            my_putstr(i > get_id_array(args,
            argc, 1) - n || tab['d'] ? "  " : "");
            my_putstr(i > get_id_array(args, argc, 1) - n
            && !tab['d'] && get_sum_array(args, argc, 1) > 1 ? "\n" : "");
            get_sum_array(args, argc, 1) > 1 && !tab['d'] ?
            my_printf("%s:\n", argv[i]) : 0;
            tab['R'] && i == 1 && get_sum_array(args, argc, 1) == 1 ?
            my_printf("%s:\n", argv[i]) : 0;
            my_ls(argv[i], tab, head, FALSE);
        }
    free_file(head);
    }
}

void sub_handle_file(char *argv[], int *args, int *tab, int j)
{
    int argc = 0;

    for (; argv[argc]; argc++);
    !tab['l'] && j > get_id_array(args, argc, 1) ? my_putstr("  ") : 0;
    tab['l'] ? format_list(argv[j], 1) : 0;
    tab['l'] ? my_printf("%s\n", argv[j]) : 0;
    !tab['l'] ? my_printf("%s", argv[j]) : 0;
}

void sub_handle(int argc, char *argv[], int *args, int *tab)
{
    struct stat st;
    int *format = malloc(sizeof(int) * 3);
    int n = 0;

    for (int i = 0; i < 3; format[i] = 1, i++);
    for (int j = 1; j < argc; j++) {
        stat(argv[j], &st);
        if (!S_ISDIR(st.st_mode) && args[j] && !tab['R']) {
            sub_handle_file(argv, args, tab, j);
        }
        n += S_ISDIR(st.st_mode) && args[j];
    }
    (n < argc - 1 && !tab['l'] && !tab['R'] && !tab['d']) ? my_putstr("\n") : 0;
    sub_handle_core(argv, args, tab, n);
}

int handle_multiple_path(int argc, char *argv[], int *args, int *tab)
{
    read_list_t *head;
    char *path = (argc - 1 && get_sum_array(args, argc, 1) ?
    argv[get_id_array(args, argc, 1)] : ".");

    if (get_sum_array(args, argc, 1) < 1) {
        head = init_file(path);
        my_ls(path, tab, head, FALSE);
        free_file(head);
    }
    sub_handle(argc, argv, args, tab);
    my_putstr(tab['d'] ? "\n" : "");
    free(args);
    return 0;
}

int main(int argc, char *argv[])
{
    int tab[256] = {0};
    int *args = malloc(sizeof(int) * argc);

    for (int i = 0; i < argc; args[i] = *argv[i] != '-', i++);
    for (int i = 1; i < argc; i++)
        if (*(argv[i]) == '-' && (get_args(tab, argv[i],
        !args[i]) || my_strlen(argv[i]) == 1)) {
            free(args);
            return 84;
        }
    return handle_multiple_path(argc, argv, args, tab);
}
