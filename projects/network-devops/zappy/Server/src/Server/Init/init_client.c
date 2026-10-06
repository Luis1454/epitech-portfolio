/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** init_client
*/

#include "../../../include/Server/init.h"

void init_inventory(server_t *server, int i)
{
    server->clients[i].request_action = 1;
    server->clients[i].inventory = malloc(sizeof(int) * 8);
    server->clients[i].inventory->food = 10;
    server->clients[i].inventory->deraumere = 0;
    server->clients[i].inventory->linemate = 0;
    server->clients[i].inventory->mendiane = 0;
    server->clients[i].inventory->phiras = 0;
    server->clients[i].inventory->sibur = 0;
    server->clients[i].inventory->thystame = 0;
}

// init all the value of the client struct part two
void init_all_value_two(server_t *server, int i)
{
    server->clients[i].is_taking = 0;
    server->clients[i].is_setting = 0;
    server->clients[i].is_inventory = 0;
    server->clients[i].is_connect_nbr = 0;
    server->clients[i].is_look = 0;
    server->clients[i].is_right = 0;
    server->clients[i].is_left = 0;
    server->clients[i].is_forward = 0;
    server->clients[i].is_incantation = 0;
    server->clients[i].is_unknown = 0;
    server->clients[i].is_broadcast = 0;
    server->clients[i].broadcast_cmd = NULL;
    server->clients[i].is_eject = 0;
    server->clients[i].is_fork = 0;
    server->clients[i].is_take_object = 0;
    server->clients[i].take_object_cmd = NULL;
    server->clients[i].is_set_object = 0;
    server->clients[i].set_object_cmd = NULL;
    server->clients[i].action = 0;
    init_inventory(server, i);
}

// init all the value of the client struct part one
void init_all_value(server_t *server, int i)
{
    server->clients[i].socket = -1;
    server->clients[i].is_connected = false;
    server->clients[i].is_gui = false;
    server->clients[i].request = NULL;
    server->clients[i].id = 0;
    server->clients[i].inventory = NULL;
    server->clients[i].x = 0;
    server->clients[i].y = 0;
    server->clients[i].width = 0;
    server->clients[i].heigt = 0;
    server->clients[i].level = 0;
    server->clients[i].orientation = 0;
    server->clients[i].is_incanting = 0;
    server->clients[i].is_dead = 0;
    server->clients[i].is_graphical = 0;
    server->clients[i].is_ejecting = 0;
    server->clients[i].is_broadcasting = 0;
    server->clients[i].request_nbr = 0;
    server->clients[i].is_forking = 0;
    init_all_value_two(server, i);
}

// init all the value of every client struct
void init_client(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++) {
        init_all_value(server, i);
    }
}
