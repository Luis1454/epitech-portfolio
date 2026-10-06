/*
** EPITECH PROJECT, 2022
** corewar.h
** File description:
** corewar.h
*/

#include "base.h"

#ifndef COREWAR_H
    #define COREWAR_H

    typedef struct process_s {
        int *reg;
        int pos;
        int pc;
        struct process_s *next;
    } process_t;

    typedef struct prog_s {
        int id;
        int head;
        int live;
        int carry;
        int nb_live;
        int address;
        int load_address;
        char *last_alive;
        int last_alive_id;
        process_t *process;
    } prog_t;

    typedef struct pool_s {
        prog_t *prog;
        int nb_prog;
        int cycle;
        int total_cycle;
        char *map;
        char *dump;
    } pool_t;

/* DISPLAY HELP */
void display_help(void);

/* OPEN FILE */
char *open_file(char *filename, int *file_size);
int verify_extension(char *filename, char *extension);

/* PARSING ARGUMENTS */
int parse_file(char *buffer, int len);
int parse_arguments(int ac, char **av);

/* ERROR HANDLER */
int error_handler(int ac, char **av);
/*---------------*/

/* LIB FUNCTION */
char *my_convert_to_hex(int nb, char *memory);
/*--------------*/

/* POOL */
void add_process(process_t **process, int pos, int *reg);
int cycle_loop(pool_t *pool, int nb);
/*------*/

/* END GAME */
void end_game(prog_t *prog);
/*---------*/

/* FLAGS HANDLING */
int dump_memory(pool_t *pool, char *memory);
int manage_laod_address(void);
int manage_prog_number(pool_t *pool, char *memory);

#endif /* COREWAR_H */

#ifndef TRUE
    #define TRUE 1
#endif /* TRUE */

#ifndef FALSE
    #define FALSE 0
#endif /* FALSE */
