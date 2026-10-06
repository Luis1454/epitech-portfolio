/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pic
*/

#include "../../../include/Command/gui_command.h"

void send_player(server_t *server, incantation_t *incantation, int client)
{
    for (int i = 0; i < incantation->nb_players; i++)
        dprintf(server->clients[client].socket, " %d",
        incantation->players[i]);
}

// start of an incantation (by the first player)
void cmd_pic(server_t *server, incantation_t *incantation)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true) {
            dprintf(server->clients[i].socket, "pic %d %d %d", incantation->x,
                incantation->y, incantation->level);
            send_player(server, incantation, i);
            dprintf(server->clients[i].socket, "\n");
        }
}
