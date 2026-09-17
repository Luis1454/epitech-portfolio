/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file for antman compression part
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

void display_bin_str(unsigned char *str, int len)
{
    unsigned char c = 0;
    int i = 0;
    int range = 1000;
    char tmp[1000] = {0};

    for (; str[i] && i < len / 8 + 1; i++) {
        for (int j = i * 8; j - i * 8 < 8 && str[j]; j++)
            c = (c << 1) | (str[j] - '0');
        if (!(i % range) && i)
            write(1, &tmp, range - i % range);
        tmp[i % range] = c;
    }
    write(1, &tmp, i % range);
    free(str);
}

int get_max(byte_t *arr)
{
    int max = 0;

    for (int i = 0; arr[i].nb != -1; i++)
        max = arr[i].nb > max ? arr[i].nb : max;
    return max;
}

void sub_main_a(unsigned char *content,
unsigned long size, char **dict, byte_t *arr)
{
    unsigned char *str = malloc(sizeof(unsigned char) * (size * 16 + 1));
    int n = 0;
    int j = 0;

    for (unsigned long i = 0; i < size; i++) {
        for (j = 0; dict[(int)content[i]][j]; j++)
            str[n + j] = dict[(int)content[i]][j];
        n += j;
    }
    str[n] = 0;
    my_putchar(n % 8);
    display_bin_str(str, n);
    for (int i = 0; i < 256; i++)
        free(dict[i]);
    free(dict);
    free(arr);
    free(content);
}

int sub_main(unsigned char *content, unsigned long size)
{
    byte_t *arr = get_array(content, size);
    char **dict = NULL;
    int len = 0;
    int block_size = 1;

    for (; my_compute_power_it(256, block_size) < get_max(arr); block_size++);
    for (len = 0; arr[len].nb != -1; len++);
    my_putchar(len - 1);
    for (int i = 0; i < len; i++)
        my_putchar(arr[i].c);
    dict = get_dictionary(arr, create_tree(arr, len), len);
    my_putchar(block_size);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < block_size; j++)
            my_putchar((int)arr[i].nb >> (block_size - j - 1) * 8);
    sub_main_a(content, size, dict, arr);
    return 0;
}

int main(int argc, char const *argv[])
{
    unsigned char *content = NULL;
    unsigned long size = 0;

    if (argc != 3) {
        my_print_error("Error: Invalid number of arguments\n");
        my_print_error("USAGE: ./antman [file] [kind]\n");
        return 84;
    }
    content = get_content((char *)argv[1], &size, 'c');
    if (content == NULL)
        return 84 + my_print_error("Error: could not open the file\n");
    if (!size) {
        free(content);
        return 0;
    }
    return sub_main(content, size);
}
