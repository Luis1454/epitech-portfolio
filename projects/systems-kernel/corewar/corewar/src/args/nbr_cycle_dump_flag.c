/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** (nbr_cycle)dump_flag.c
*/

#include "lib.h"

char *my_convert_to_hex(int nb, char *memory)
{
    char *hex = "0123456789ABCDEF";
    char *result = malloc(sizeof(char) * 3);
    int i = 0;

    for (; nb != 0; i++) {
        result[i] = hex[nb % 16];
        nb /= 16;
    }
    result[i] = '\0';
    if (i == 1)
        result[i] = '0';
    result = my_revstr(result);
    memory = my_strcat(memory, result);
    return memory;
}

int sub_dump_memory(char *memory)
{
    for (int i = 0; memory[i] != '\0'; i++) {
        char str[2] = { memory[i], '\0'};
        if (!my_str_isalphanum(str)) {
            my_putstr_error("Error: Invalid memory\n");
            return 84;
        }
    }
    return 0;
}

int dump_memory(pool_t *pool, char *memory)
{
    int cycle = 0;
    char *memory_binary;

    sub_dump_memory(memory);
    memory_binary = my_convert_to_hex(42, memory);
    cycle = my_getnbr(memory_binary, ' ');
    if (cycle <= 0) {
        my_putstr_error("Error: Invalid cycle\n");
        return 84;
    }
    pool->dump = my_strdup(memory);
    pool->cycle = cycle;
    return 0;
}
