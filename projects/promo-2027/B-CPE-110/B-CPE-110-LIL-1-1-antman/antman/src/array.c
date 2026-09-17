/*
** EPITECH PROJECT, 2023
** array.c
** File description:
** array functions
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

static byte_t *sub_sort_array(byte_t *arr, byte_t tmp, int size)
{
    for (int j = 0; j < size - 1; j++) {
        if (arr[j].nb < arr[j + 1].nb) {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
        }
    }
    return arr;
}

byte_t *my_sort_array(byte_t *arr, int size)
{
    byte_t tmp = {0, 0};

    for (int i = 0; i < size; i++)
        arr = sub_sort_array(arr, tmp, size);
    return arr;
}

byte_t *get_array(unsigned char *content, int size)
{
    byte_t *arr = NULL;
    int n = 0;
    int ascii[256] = {0};

    for (int i = 0; i < size; i++) {
        ascii[(unsigned char)content[i]]++;
        n += ascii[(unsigned char)content[i]] == 1;
    }
    arr = malloc(sizeof(byte_t) * (n + 1));
    if (arr == NULL)
        return NULL;
    for (int i = 0, j = 0; i < 256; i++) {
        if (ascii[i]) {
            arr[j].nb = ascii[i];
            arr[j].c = i;
            j++;
        }
    }
    arr[n].nb = -1;
    return my_sort_array(arr, n);
}

node_t *search_node(node_t *head, unsigned char c)
{
    node_t *tmp = NULL;

    if (head == NULL)
        return NULL;
    if (head->byte.c == c)
        return head;
    tmp = search_node(head->left, c);

    if (tmp)
        return tmp;
    return search_node(head->right, c);
}
