/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** handle_first_connection
*/

#include "../../include/Server/server.h"
#include "../../include/Command/gui_command.h"
#include "../../include/Command/client_command.h"

// send pnw to the gui for init the client in gui
void send_pnw_gui(server_t *server, int i)
{
    player_t player;

    if (server->clients[i].is_connected == false)
        return;
    player.player_id = server->clients[i].id;
    player.x = server->clients[i].x;
    player.y = server->clients[i].y;
    player.orientation = server->clients[i].orientation;
    player.level = server->clients[i].level;
    player.team_name = server->clients[i].team_name;
    cmd_pnw(server, &player);
}

// send pnw to the gui for init the client in gui
void send_pnw_client(server_t *server, int i)
{
    player_t player;

    player.player_id = server->clients[i].id;
    player.x = server->clients[i].x;
    player.y = server->clients[i].y;
    player.orientation = server->clients[i].orientation;
    player.level = server->clients[i].level;
    player.team_name = server->clients[i].team_name;
    cmd_pnw(server, &player);
}

// send all the command for the first connection of the gui
void send_first_connection_gui(server_t *server)
{
    cmd_msz(server);
    cmd_bct(server);
    cmd_sgt(server);
    cmd_tna(server);
    for (int i = 0; i < server->nbr_clients_connected; i++)
        send_pnw_gui(server, i);
}

// replace the egg if the egg is already fork by a client
static void replace_egg(server_t *server, int client, int i)
{
    int val = 0;

    val = server->serverConfig->teams[i].fork;
    server->clients[client].x = server->serverConfig->teams[i].egg[val].x;
    server->clients[client].y = server->serverConfig->teams[i].egg[val].y;
    server->serverConfig->teams[i].egg[val].is_fork = 0;
    if (server->serverConfig->teams[i].fork > 0)
        server->serverConfig->teams[i].fork--;
    cmd_ebo(server, server->serverConfig->teams[i].
    egg[server->serverConfig->teams[i].fork].id);
    return;
}

// set all the value for the client struct for the first connection
void set_value_for_client(server_t *server, int client, char *buffer)
{
    server->clients[client].team_name = strdup(buffer);
    server->clients[client].level = 1;
    server->clients[client].orientation = rand() % 4 + 1;
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name,
        server->clients[client].team_name) == 0 &&
        server->serverConfig->teams[i].fork > 0 &&
        server->serverConfig->teams[i].
        egg[server->serverConfig->teams[i].fork].is_fork == 1)
            return replace_egg(server, client, i);
    server->clients[client].x = rand() % server->serverConfig->map_width;
    server->clients[client].y = rand() % server->serverConfig->map_height;
}

// send the first connection to the client
void send_first_connection_client(server_t *server, int client)
{
    char msg[BUFFER_SIZE];
    int number_place_available = 0;
    int len = 0;

    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name,
            server->clients[client].team_name) == 0) {
            number_place_available = server->serverConfig->client_nb -
            server->serverConfig->teams[i].client_nbr;
        }
    len = snprintf(msg, BUFFER_SIZE, "%d\n%d %d\n",
        number_place_available, server->serverConfig->map_width,
        server->serverConfig->map_height);
    send(server->clients[client].socket, msg, len, 0);
}
