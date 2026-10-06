/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** entries_error.c
*/

#include "asm_corewar.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./asm file_name[.s]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile_name\tfile in assembly language to be converted ");
    my_putstr("into file_name.cor, an\n\t\t\texecutable in the Virtual ");
    my_putstr("Machine.\n");
    return 1;
}

int error_handler(int ac, char **av)
{
    int help_i = 0;
    if (ac != 2)
        return 84;
    if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_i = help();
    return help_i;
}
