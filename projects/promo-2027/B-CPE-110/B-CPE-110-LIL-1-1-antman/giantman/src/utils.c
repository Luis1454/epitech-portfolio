/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils functions
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

char *bin_to_str(int b, int n)
{
    char *str = malloc(sizeof(char) * 9);

    for (int i = 0; i < 9; i++)
        str[i] = 0;
    for (int i = 0; i < n; i++) {
        str[i] = (b & 1) + '0';
        b >>= 1;
    }
    return my_revstr(str);
}

char *get_code(unsigned char *str, int size, int offset)
{
    char *code = malloc(sizeof(char) * (size * 8 + 1));
    int n = 0;

    for (int i = 0; i < size * 8 + 1; i++)
        code[i] = 0;
    for (int i = 0; i < size + 1; i++, n += 8)
        my_strncat_at(code, bin_to_str(str[i],
        i < size ? 8 : offset), n, n - offset);
    code[size * 8] = 0;
    return code;
}

void set_data(node_t **tmp, char c)
{
    c == '0' ? *tmp = (*tmp)->left : c == '1' ? *tmp = (*tmp)->right : 0;
}

void print_char_from_code(char *code, node_t *head, int size, int n)
{
    node_t *tmp = head;
    char t[1000] = {0};
    int range = 1000;

    for (int i = 0; i < (size) * 8; i++) {
        set_data(&tmp, code[i]);
        if (tmp && tmp->left == NULL && tmp->right == NULL) {
            !(n % range) && n ? write(1, &t, range - n % range) : 0;
            t[n % range] = tmp->byte.c;
            tmp = head;
            n++;
        }
    }
    write(1, &t, n % range);
    free_tree(head);
    free(code);
}

int get_nbr_from_chars(unsigned char *str, int min, int max, int block_size)
{
    int nb = 0;

    for (int i = min; i < max; i++)
        nb += str[i] * my_compute_power_it(256, block_size - i + min - 1);
    return nb;
}
