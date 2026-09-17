/*
** EPITECH PROJECT, 2023
** display_b.c
** File description:
** display functions
*/

#include "../include/fasta.h"
#include "../include/my.h"

int display_four(char **arr, int size)
{
    list_t *head = NULL;
    list_t *last = head;
    char *tmp = NULL;

    if (!size)
        return 84;
    for (int i = 0; arr[i]; i++) {
        arr[i] = my_strupcase(arr[i]);
        for (int j = 0; j < my_strlen(arr[i]) - size + 1; j++) {
            tmp = my_strndup(arr[i] + j, size);
            append_node(&head, tmp);
            free(tmp);
        }
    }
    sort_node(&head);
    for (list_t *ll_tmp = head; ll_tmp; last = ll_tmp, ll_tmp = ll_tmp->next)
        if (!last || my_strcmp(last->str, ll_tmp->str))
            my_printf("%s\n", ll_tmp->str);
    return 0;
}

void sub_five(list_t **out, list_t **last, char **arr, int i)
{
    char *end[] = {"TAG", "TAA", "TGA", NULL};
    list_t *head = NULL;
    char *tmp = NULL;

    for (int j = 0; j < my_strlen(arr[i]) - 3 + 1; j++)
        if (start_by(&arr[i][j], "ATG")) {
            tmp = my_strdup(arr[i] + j);
            append_node(&head, tmp);
            free(tmp);
        }
    for (list_t *ll_tmp = head; ll_tmp; *last = ll_tmp, ll_tmp = ll_tmp->next)
        if (!(get_str_pos(&ll_tmp->str[1], end) % 3)
        && str_in_strs(ll_tmp->str, end)) {
            ll_tmp->str[get_str_pos(ll_tmp->str, end)] = 0;
            append_node(out, ll_tmp->str);
        }
}

int display_five(char **name, char **arr)
{
    list_t *last = NULL;
    list_t *out = NULL;

    for (int i = 0; arr[i]; i++) {
        arr[i] = my_strupcase(arr[i]);
        sub_five(&out, &last, arr, i);
        sort_node(&out);
        for (list_t *ll_tmp = out; ll_tmp; ll_tmp = ll_tmp->next)
            !last || my_strcmp(last->str, ll_tmp->str)
            ? my_printf("%s\n", ll_tmp->str) : 0;
    }
    return 0;
}
