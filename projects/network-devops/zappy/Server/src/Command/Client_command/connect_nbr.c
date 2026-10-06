/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** nbr_team_slot
*/

#include "../../../include/Command/client_command.h"

static void make_connect_nbr(client_t *client, char *cmd, server_t *server)
{
    int id_team = 0;

    (void)server;
    (void)cmd;
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name,
        client->team_name) == 0) {
            id_team = i;
            break;
        }
    dprintf(client->socket, "%d\n",
    server->serverConfig->teams[id_team].number_place_available);
}

void send_connect_nbr(client_t *client, char *cmd, server_t *server)
{
    if (client->is_connect_nbr == 1) {
        make_connect_nbr(client, cmd, server);
        client->is_connect_nbr = 0;
        client->request_action = 0;
    }
}

void cmd_connect_nbr(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_connect_nbr = 1;
    client->action = 0;
}
