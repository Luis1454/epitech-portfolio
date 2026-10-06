/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** tna
*/

#include "../../../include/Command/gui_command.h"

void send_all_teams(server_t *server, int client)
{
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        dprintf(server->clients[client].socket, "tna %s\n",
            server->serverConfig->teams[i].name);
}

// name of all the teams
void cmd_tna(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            send_all_teams(server, i);
}
