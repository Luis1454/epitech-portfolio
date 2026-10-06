/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** exector_cmds_tools.c
*/

#include "lib.h"

int get_exec_address(prog_t *prog)
{
    int address = prog->address + prog->process->pc;
    return (select_correct_address(address));
}

int select_correct_address(int address)
{
    while (address >= MEM_SIZE)
        address = address - MEM_SIZE;
    while (address < 0)
        address = MEM_SIZE + address;
    return (address);
}

void add_pc(int *pc, int value)
{
    *pc = *pc + value;
    if (*pc > 65535)
        *pc = *pc - 65536;
    if (*pc < 0)
        *pc = 65536 + *pc;
}
