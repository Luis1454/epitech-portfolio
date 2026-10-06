/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** display_help.c
*/

#include "lib.h"

void display_help(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cyle] [[-n prog_number] [-a lo"
    "ad_address] prog_name ...\nDESCRIPTION\n-dump nbr_cycle dumps the me"
    "mory after the nbr_cycle execution (if the round isn't already over)"
    " with the following format: 32 bytes/line in hexadecimal (AOBCDEFE1D"
    "D3...)\n-n prog_number sets the next program's number. By default, t"
    "he first free number in the parameter order\n-a load_address sets th"
    "e next program's loading address. When no address is specified, opti"
    "mize the address so that the processes are as far awat from each as "
    "possible. The addresses are MEM_SIZE modulo.\n");
}
