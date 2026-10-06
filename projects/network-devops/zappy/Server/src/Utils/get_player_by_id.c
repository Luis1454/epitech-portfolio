/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** get_player_by_id
*/

#include "../../include/Utils/utils.h"

// get the player struct by his id
client_t *get_player_by_id(server_t *server, int player_id)
{
    for (int i = 0; i < server->nbr_clients_connected; i++)
        if (server->clients[i].id == player_id)
            return &server->clients[i];
    return NULL;
}
