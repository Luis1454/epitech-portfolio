/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** gestion_command
*/

#include "../../../include/Command/client_command.h"

// Send the response to the client
void send_response(client_t *client, char *cmd, server_t *server)
{
    send_broadcast(client, cmd, server);
    send_connect_nbr(client, cmd, server);
    send_eject(client, cmd, server);
    send_fork(client, cmd, server);
    send_forward(client, cmd, server);
    send_incantation(client, cmd, server);
    send_inventory(client, cmd, server);
    send_left(client, cmd, server);
    send_look(client, cmd, server);
    send_right(client, cmd, server);
    send_set_object(client, cmd, server);
    send_take_object(client, cmd, server);
}

// Send the broadcast to the client
void all_condition_two(server_t *server, int client, char *buffer)
{
    if (strcmp(buffer, "Connect_nbr") == 0)
        cmd_connect_nbr(&server->clients[client], buffer);
    if (strcmp(buffer, "Fork") == 0)
        cmd_fork(&server->clients[client], buffer);
    if (strcmp(buffer, "Eject") == 0)
        cmd_eject(&server->clients[client], buffer);
    if (strncmp(buffer, "Take", 4) == 0)
        cmd_take_object(&server->clients[client], buffer);
    if (strncmp(buffer, "Set", 3) == 0)
        cmd_set_object(&server->clients[client], buffer);
    if (strcmp(buffer, "Incantation") == 0)
        cmd_incantation(&server->clients[client], buffer, server);
}

void all_condition(server_t *server, int client, char *buffer)
{
    if (strcmp(buffer, "Forward") == 0)
        cmd_forward(&server->clients[client], buffer);
    if (strcmp(buffer, "Right") == 0)
        cmd_right(&server->clients[client], buffer);
    if (strcmp(buffer, "Left") == 0)
        cmd_left(&server->clients[client], buffer);
    if (strcmp(buffer, "Look") == 0)
        cmd_look(&server->clients[client], buffer);
    if (strcmp(buffer, "Inventory") == 0)
        cmd_inventory(&server->clients[client], buffer);
    if (strncmp(buffer, "Broadcast", 9) == 0)
        cmd_broadcast(&server->clients[client], buffer);
    all_condition_two(server, client, buffer);
}

void remove_first_request(char **request)
{
    if (request == NULL)
        return;
    for (int i = 0; request[i] != NULL; i++) {
        request[i] = request[i + 1];
    }
}

// Handle the command sent by a client
void handle_clients_command(server_t *server, int client, char *buffer)
{
    if (server->clients[client].action != 0) {
        server->clients[client].action -= 1;
        return;
    }
    send_response(&server->clients[client], buffer, server);
    if (buffer != NULL)
        all_condition(server, client, buffer);
    remove_first_request(server->clients[client].request);
    if (server->clients[client].request_action == 0) {
        server->clients[client].request_nbr -= 1;
        server->clients[client].request_action = 1;
    }
}
