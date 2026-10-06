/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** corewar.h
*/

#include "base.h"
#include "lib.h"

#ifndef ASM_COREWAR_H
    #define ASM_COREWAR_H

    typedef struct champion_s {
        int line_b_label;
        char ***label_name;
        int nb_champ;
    } champion_t;

    extern champion_t *champ;

    typedef struct cmd_s {
        int idx;
        int *arg;
    } cmd_t;

    typedef struct idx_w_value_s {
        int idx;
        int value;
    } idx_w_value_t;

/* ERROR HANDLER */
    int error_handler(int ac, char **av);
/*---------------*/

/* COMPILER */
    int compiler(char *filepath, champion_t *champion);
    int open_file(char *filepath);
/*----------*/

/* FILL CHAMPION */
    int fill_champion(champion_t *champion, char *buffer, char *filepath);
    int fill_header(header_t *header, char **array, char *line, int fd);
    int fill_comment(header_t *header, char **array, char *line, int fd);
    char *select_command(char *command, champion_t *champion, int fd);
    int content_all(char *filepath, char **content);
    int find_label(char *line, champion_t *champion);
    int revbytes(int value);
    int find_label_w(char *command);
/*---------------*/

/* COMMAND */
    void write_command(int fd, champion_t *champion, char **content);
    int find_cmd(char *line, int fd, champion_t *champion);
    int live(char **command, int fd);
    int ld_c(char **command, int fd);
    int st_c(char **command, int fd);
    int add(char **command, int fd);
    int and_r_r(char **command, int fd, int idx );
    int and_r_d(char **command, int fd, int idx );
    int and_r_i(char **command, int fd, int idx );
    int and_d_r(char **command, int fd, int idx );
    int and_d_d(char **command, int fd, int idx );
    int and_d_i(char **command, int fd, int idx );
    int and_i_r(char **command, int fd, int idx );
    int and_i_d(char **command, int fd, int idx );
    int and_i_i(char **command, int fd, int idx );
    int and_2(char **command, int fd, int idx );
    int sub(char **command, int fd);
    int and_c(char **command, int fd);
    int or_c(char **command, int fd);
    int xor_c(char **command, int fd);
    int zjmp(char **command, int fd);
    int ldi(char **command, int fd);
    int sti(char **command, int fd);
    int fork_a(char **command, int fd);
    int lld(char **command, int fd);
    int lldi(char **command, int fd);
    int lfork(char **command, int fd);
    int aff(char **command, int fd);
    int direct(char *command, int nb_arg);
    int indirect(char *command, int nb_arg);
    int register_f(char *command, int nb_arg);
    int encoded_type(int arg1, int arg2, int arg3, int arg4);
    void write_all(int fd, int *arg, int idx, char **command);
    int sti_i_d(char **command, int fd, int idx );
    int sti_i_r(char **command, int fd, int idx );
/*---------*/

/* PARSER */
    void parse_file(char *buffer);
/*--------*/

#endif //ASM_COREWAR_H
