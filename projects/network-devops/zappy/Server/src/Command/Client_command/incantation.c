/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** incantation
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

static void add_level(server_t *server, client_t *client)
{
    client_t *other_client;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        other_client = &server->clients[i];
        if (other_client->is_gui == true)
            continue;
        if (other_client->x == client->x && other_client->y ==
            client->y && other_client->level == client->level) {
            other_client->level++;
            dprintf(other_client->socket,
            "Current level: %d\n", other_client->level);
        }
    }
}

static void apply_elevation4(tile_t *tile, int level)
{
    switch (level) {
        case 7:
            tile->linemate -= 1;
            tile->deraumere -= 2;
            tile->sibur -= 3;
            tile->phiras -= 1;
            break;
        case 8:
            tile->linemate -= 2;
            tile->deraumere -= 2;
            tile->sibur -= 2;
            tile->mendiane -= 2;
            tile->phiras -= 2;
            tile->thystame -= 1;
            break;
        default:
            break;
    }
}

static void apply_elevation3(tile_t *tile, int level)
{
    switch (level) {
        case 4:
            tile->linemate -= 2;
            tile->sibur -= 1;
            tile->phiras -= 2;
            break;
        default:
            apply_elevation4(tile, level);
            break;
    }
}

static void apply_elevation2(tile_t *tile, int level)
{
    switch (level) {
        case 5:
            tile->linemate -= 1;
            tile->deraumere -= 1;
            tile->sibur -= 2;
            tile->phiras -= 1;
            break;
        case 6:
            tile->linemate -= 1;
            tile->deraumere -= 2;
            tile->sibur -= 1;
            tile->mendiane -= 3;
            break;
        default:
            apply_elevation3(tile, level);
            break;
    }
}

static void apply_elevation(client_t *client, server_t *server, int level)
{
    tile_t *tile = &server->serverConfig->map->tiles[client->y][client->x];

    add_level(server, client);
    switch (level) {
        case 2:
            tile->linemate -= 1;
            break;
        case 3:
            tile->linemate -= 1;
            tile->deraumere -= 1;
            tile->sibur -= 1;
            break;
        default:
            apply_elevation2(tile, level);
            break;
    }
}

// make the elevation level
static void make_incantation(client_t *client, char *cmd, server_t *server)
{
    incantation_t incantation;

    (void)cmd;
    apply_elevation(client, server, client->level + 1);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_connected == false ||
            server->clients[i].is_gui == true)
            continue;
    }
    cmd_plv(server, client->id, client->level);
    incantation.x = client->x;
    incantation.y = client->y;
    incantation.result = 0;
    cmd_pie(server, &incantation);
}

// send the incantation
void send_incantation(client_t *client, char *cmd, server_t *server)
{
    if (client->is_incantation == 1) {
        make_incantation(client, cmd, server);
        client->is_incantation = 0;
        client->request_action = 0;
    }
}

void init_incantation(client_t *client, incantation_t *incantation)
{
    client->is_incantation = 1;
    client->action = 300;
    incantation->x = client->x;
    incantation->y = client->y;
    incantation->level = client->level;
    incantation->nb_players = 1;
    incantation->players[0] = client->id;
}

void cmd_incantation(client_t *client, char *cmd, server_t *server)
{
    incantation_t incantation;

    (void)cmd;
    if (condition_to_elevation(client, server) == false) {
        send(client->socket, "ko\n", 3, 0);
        return;
    }
    init_incantation(client, &incantation);
    cmd_pic(server, &incantation);
    send(client->socket, "Elevation underway\n", 20, 0);
}
