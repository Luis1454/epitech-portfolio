/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "../include.h"
    #include <stdarg.h>
    #include "../Server/server.h"

void write_log_file(char *str, ...);
client_t *get_player_by_id(server_t *server, int player_id);
char *add_in_str(char *ref, char *to_add);
char **str_to_word_array(char *str, char *delim);

#endif /* !UTILS_H_ */
