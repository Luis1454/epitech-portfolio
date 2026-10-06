/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** my own ls function
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/mylist.h"

read_list_t *init_file(char *var)
{
    DIR *dir = opendir(var);
    read_list_t *node = malloc(sizeof(read_list_t));
    read_list_t *head = node;
    read_list_t *last = NULL;

    if (!dir)
        return NULL;
    for (; (node->data = readdir(dir)); last = node, node = node->next) {
        node->next = malloc(sizeof(read_list_t));
        node->prev = last;
    }
    last->next = NULL;
    my_sort_list(head);
    return head;
}

void free_file(read_list_t *file)
{
    read_list_t *h = file;
    read_list_t *next;

    while (h) {
        next = h->next;
        free(h);
        h = next;
    }
    free(h);
}

int dot_filled(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != '.')
            return 0;
    return 1;
}

void sub_my_ls(read_list_t *head, char *str, int *tab, int skip_folders)
{
    read_list_t *h;
    read_list_t *sub;
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1000);
    my_memset(tmp, 0, my_strlen(str) + 1000);

    for (h = head; h != NULL; h = h->next)
        if (!dot_filled(h->data->d_name)
        && (*h->data->d_name != '.' || tab['a'])) {
            str = my_strlen(str) > 1 ? my_weak_strcat(str,
            str[my_strlen(str) - 1] == '/' ? "" : "/") : "./";
            my_strcpy(tmp, str);
            tmp = my_weak_strcat(tmp, h->data->d_name);
            sub = init_file(tmp);
            sub ? my_printf("\n%s:\n", tmp) : 0;
            sub && (*h->data->d_name != '.' || tab['a']) ?
            my_ls(tmp, tab, sub, skip_folders) : 0;
            free_file(sub);
        }
    free(tmp);
}

int my_ls(char *str, int *tab, read_list_t *head, int skip_folders)
{
    int nb = 6;
    int wrap[3] = {tab['f'], skip_folders, 0};
    int sum = 0;

    tab['t'] ? sort_by_time(head) : 0;
    tab['r'] ? rev_read_list(&head) : 0;
    if (tab['d'])
        return my_printf("%s", str);
    if (tab['l']) {
        sum = display_list(head, tab, str, wrap);
        my_printf("total %i\n", sum / 2);
        wrap[2] = 1;
        display_list(head, tab, str, wrap);
    } else
        display_asc(head, tab, nb, wrap);
    tab['R'] ? sub_my_ls(head, str, tab, skip_folders) : 0;
    return 0;
}
