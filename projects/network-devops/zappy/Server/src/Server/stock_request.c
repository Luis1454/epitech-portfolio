/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** stock_request
*/

#include "../../include/Server/server.h"
#include "../../include/Command/client_command.h"

// stock the request of the client in request array of the client
void stock_request(server_t *server, char *buffer, int client)
{
    if (server->clients[client].request == NULL) {
        server->clients[client].request = malloc(sizeof(char *) *
        MAX_REQUEST);
        for (int i = 0; i < MAX_REQUEST; i++)
            server->clients[client].request[i] = NULL;
    }
    for (int i = 0; i < MAX_REQUEST; i++)
        if (server->clients[client].request[i] == NULL) {
            server->clients[client].request[i] = strdup(buffer);
            server->clients[client].request_nbr++;
            break;
        }
}

int verif_client_connected(server_t *server)
{
    int cmpt_client = 0;

    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (server->serverConfig->teams[i].client_nbr > 0)
            cmpt_client++;
    if (server->update != cmpt_client) {
        printf("%d team contains at least one player on %d teams\n",
        cmpt_client, server->serverConfig->teams_nb);
        server->update = cmpt_client;
    }
    if (cmpt_client >= server->serverConfig->teams_nb) {
        server->start_game = true;
        printf("Start the game\n");
        return 1;
    }
    return 0;
}

// execute the command of the client
void exec_stocked_command(server_t *server)
{
    if (server->start_game == false) {
        verif_client_connected(server);
        return;
    }
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (server->clients[i].request_nbr > 0)
            handle_clients_command(server, i, server->clients[i].request[0]);
}
