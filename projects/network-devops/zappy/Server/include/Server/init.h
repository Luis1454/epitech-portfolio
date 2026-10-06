/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** init
*/

#ifndef INIT_H_
    #define INIT_H_

    #define FOOD_D 0.5
    #define LINEMATE_D 0.3
    #define DERAUMERE_D 0.15
    #define SIBUR_D 0.1
    #define MENDIANE_D 0.1
    #define PHIRAS_D 0.08
    #define THYSTAME_D 0.05
    #include "server.h"

void resource_number(int map_width, int map_height, int *quantities);
void init_server(server_t *server);
void init_map(server_t *server);
void init_client(server_t *server);
void init_all_value(server_t *server, int i);

#endif /* !INIT_H_ */
