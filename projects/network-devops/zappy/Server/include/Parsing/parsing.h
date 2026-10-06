/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** parsing
*/

#include "error.h"
#include <ifaddrs.h>
#include "../Server/server_struct.h"
#include "../include.h"

#ifndef PARSING_H_
    #define PARSING_H_

int get_param(int ac, char *av[], serverConfig_t *serverConfig);
int print_usage(void);
void print_world_info(serverConfig_t *serverConfig);

#endif /* !PARSING_H_ */
