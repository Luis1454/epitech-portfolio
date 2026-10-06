/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** linked lists functions
*/

#include "../include/fasta.h"
#include "../include/my.h"

void append_node(list_t **head, char *str)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *head;

    if (!node)
        return;
    node->str = my_strdup(str);
    node->next = NULL;
    if (!*head) {
        *head = node;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = node;
}

void get_list(list_t **list, char **arr, int size)
{
    char *tmp = NULL;

    for (int i = 0; arr[i]; i++) {
        arr[i] = my_strupcase(arr[i]);
        for (int j = 0; j < my_strlen(arr[i]) - size + 1; j++) {
            tmp = my_strndup(arr[i] + j, size);
            append_node(list, tmp);
            free(tmp);
        }
    }
}

char **my_arrdup(char **src)
{
    char **out = NULL;
    int len = 0;

    for (; src[len]; len++);
    out = malloc(sizeof(char *) * (len + 1));
    if (!out)
        return NULL;
    for (int i = 0; src[i]; i++)
        out[i] = my_strdup(src[i]);
    out[len] = NULL;
    return out;
}
