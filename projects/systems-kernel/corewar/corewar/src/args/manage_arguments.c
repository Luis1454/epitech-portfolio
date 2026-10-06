/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** manage_arguments.c
*/

#include "lib.h"

int manage_all_flags(char **av, int i, pool_t *pool)
{
    char *memory = NULL;

    if (my_strcmp(av[i], "-dump") == 0) {
        memory = my_strdup(av[i + 1]);
        dump_memory(pool, memory);
        return 0;
    }
    if (my_strcmp(av[i], "-n") == 0) {
        manage_prog_number(pool, memory);
        return 0;
    }
    if (my_strcmp(av[i], "-a") == 0) {
        manage_laod_address();
        return 0;
    }
    my_putstr_error("Error: Invalid flag\n");
    return 1;
}

int manage_open_file(char **av, int i, int *file_size)
{
    char *file_contents = NULL;

    if (verify_extension(av[i], ".cor")) {
        my_putstr_error("Error: File extension must be '.cor'\n");
        return 84;
    }
    if ((file_contents = open_file(av[i], file_size)) == NULL
    || parse_file(file_contents, *file_size)) {
        my_putstr_error("Error: File doesn't exist\n");
        return 84;
    }
    return 0;
}

int sub_parse_args(int ac, char **av, pool_t *pool, int file_size)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' &&
        manage_all_flags(av, i++, pool))
            return 84;
        if (av[i][0] == '-')
            continue;
        if (manage_open_file(av, i, &file_size))
            return 84;
        if (cycle_loop(pool, 2))
            return 84;
    }
    return 0;
}

int parse_arguments(int ac, char **av)
{
    pool_t *pool = malloc(sizeof(pool_t));
    int file_size = 0;

    if (!pool)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        return 0;
    }
    if (ac <= 2 || ac >= 22) {
        my_putstr_error("Error: Invalid number of arguments. See the -h.\n");
        return 84;
    }
    if (sub_parse_args(ac, av, pool, file_size))
        return 84;
    return 0;
}
