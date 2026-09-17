/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils functions
*/

#include "../include/mylist.h"
#include "../include/my.h"
#include "../include/my_macro_abs.h"

int is_sorted_by_time_list(read_list_t *node)
{
    for (; node->next->next != NULL; node = node->next)
        if (get_lower_time(node->data->d_name, node->next->data->d_name) > 0)
            return 0;
    return 1;
}

int is_sorted_array(char *arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (get_lower_str(arr[i], arr[i + 1]) > 0)
            return 0;
    return 1;
}

void my_sort_list(read_list_t *head)
{
    while (!is_sorted_list(head))
        for (read_list_t *node = head; node->next; node = node->next)
            get_lower_str(node->data->d_name, node->next->data->d_name) > 0 ?
            swap_node(node, node->next) : 0;
}

void sort_by_time(read_list_t *head)
{
    while (!is_sorted_by_time_list(head))
        for (read_list_t *node = head; node->next; node = node->next)
            get_lower_time(node->data->d_name, node->next->data->d_name) ?
            swap_node(node, node->next) : 0;
}

char *drop_filename(char *str)
{
    int nb = 0;

    for (; str[nb] && str[nb] != '/'; nb++);
    if (nb == my_strlen(str))
        return "../";
    for (int i = my_strlen(str) - 1; i >= 0 && str[i] != '/'; i--)
        str[i] = 0;
    return str;
}
