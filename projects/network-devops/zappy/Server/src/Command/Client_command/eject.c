/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** eject
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Utils/utils.h"
#include "../../../include/Command/gui_command.h"

// find the orientation of the player
void get_new_pos(int x, int y, client_t *client, server_t *server)
{
    switch (client->orientation) {
        case 4:
            y = (y - 1 + client->heigt) % client->heigt;
            break;
        case 1:
            x = (x + 1) % client->width;
            break;
        case 2:
            y = (y + 1) % client->heigt;
            break;
        case 3:
            x = (x - 1 + client->width) % client->width;
            break;
    }
    client->x = x;
    client->y = y;
    server->serverConfig->map->tiles[client->y][client->x].player++;
    write_log_file("Client %d ejected to the position (%d, %d)\n",
    client->socket, x, y);
}

// destroy the egg and send edi message to the client
static int destroy_eggs2(server_t *server, int y, int x, int i)
{
    for (int j = 0; j < server->serverConfig->teams[i].fork; j++) {
        if (server->serverConfig->teams[i].egg[j].x == x &&
            server->serverConfig->teams[i].egg[j].y == y) {
            server->serverConfig->teams[i].egg[j].is_fork = 0;
            server->serverConfig->teams[i].egg[j].x = -1;
            server->serverConfig->teams[i].egg[j].y = -1;
            cmd_edi(server, server->serverConfig->teams[i].egg[j].id);
            server->serverConfig->teams[i].egg[j].id = -1;
            return 0;
        }
    }
    return 0;
}

// if there is an egg in the tile, destroy it
static int destroy_eggs(server_t *server, int y, int x)
{
    if (server->serverConfig->map->tiles[y][x].egg == true) {
        server->serverConfig->map->tiles[y][x].egg = false;
        for (int i = 0; i < server->serverConfig->teams_nb; i++)
            return destroy_eggs2(server, y, x, i);
    }
    return 0;
}

// send eject message to the client
void notify_eject(int client_socket,
    int client_or, int other_or)
{
    int final_or = -1;

    final_or = find_orientation(client_or, other_or);
    dprintf(client_socket, "eject: %d\n", final_or);
}

// eject all the player of the tile of the current player.
int eject_action(server_t *server, client_t *client)
{
    int is_player = 0;
    client_t *other_client;

    for (int i = 0; i < server->nbr_clients_connected; ++i) {
        other_client = &server->clients[i];
        if (other_client->x == client->x && other_client->y == client->y &&
            other_client->socket != client->socket) {
            is_player++;
            server->serverConfig->map->tiles[other_client->y]
            [other_client->x].player--;
            get_new_pos(client->x, client->y, other_client, server);
            notify_eject(other_client->socket,
            client->orientation, other_client->orientation);
        }
    }
    destroy_eggs(server, client->y, client->x);
    cmd_pex(server, client->socket);
    return (is_player);
}

// make the eject
static void make_eject(client_t *client, char *cmd, server_t *server)
{
    int result = -1;

    (void)cmd;
    result = eject_action(server, client);
    if (result <= 0)
        send(client->socket, "ko\n", 3, 0);
    else
        send(client->socket, "ok\n", 3, 0);
}

// send the eject
void send_eject(client_t *client, char *cmd, server_t *server)
{
    if (client->is_eject == 1) {
        make_eject(client, cmd, server);
        client->is_eject = 0;
        client->request_action = 0;
    }
}

// eject command
void cmd_eject(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_eject = 1;
    client->action = 7;
}
