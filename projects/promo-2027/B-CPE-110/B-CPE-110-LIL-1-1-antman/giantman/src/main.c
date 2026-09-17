/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file for decompression part
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

int init_giantman(unsigned char *str, int size, int len)
{
    byte_t *arr = malloc(sizeof(byte_t) * (size + 1));
    int block_size = str[size + 1];
    int offset = str[size + 2 + size * block_size];

    if (arr == NULL)
        return 1;
    arr[size].nb = -1;
    arr[size].c = 0;
    for (int i = 0; i < size; i++) {
        arr[i].c = str[i + 1];
        arr[i].nb = get_nbr_from_chars(str, i * block_size + 2 + size,
        (i + block_size) * block_size + 2 + size, block_size);
    }
    print_char_from_code(get_code(&str[1 + size + 1 + size * block_size],
    len - (1 + size + 1 + size * block_size + 1), offset),
    create_tree(arr, size), len - (1 + size + 1 + size * block_size + 1), 0);
    free(arr);
    return 0;
}

int sub_main(const char *file)
{
    unsigned long size = 0;
    int nb_chars = 0;
    unsigned char *content = get_content(file, &size, 'd');

    if (content == NULL)
        return 84;
    if (!size)
        return 0;
    nb_chars = content[0] + 1;
    init_giantman(content, nb_chars, size);
    free(content);
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        my_print_error("Usage: ./giantman [file] [kind]\n");
        return 84;
    }
    return sub_main(argv[1]);
}
