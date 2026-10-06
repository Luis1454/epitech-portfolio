/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** take_object
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// list of resources 4
static void take_resource4(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "thystame") == 0) {
        if (tile->thystame > 0) {
            tile->thystame--;
            client->inventory->thystame++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
    } else
        send(client->socket, "ko\n", 3, 0);
}

// list of resources 3
static void take_resource3(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "mendiane") == 0) {
        if (tile->mendiane > 0) {
            tile->mendiane--;
            client->inventory->mendiane++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    if (strcmp(resource, "phiras") == 0) {
        if (tile->phiras > 0) {
            tile->phiras--;
            client->inventory->phiras++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    take_resource4(client, resource, tile);
}

// list of resources 2
static void take_resource2(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "deraumere") == 0) {
        if (tile->deraumere > 0) {
            tile->deraumere--;
            client->inventory->deraumere++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    if (strcmp(resource, "sibur") == 0) {
        if (tile->sibur > 0) {
            tile->sibur--;
            client->inventory->sibur++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    take_resource3(client, resource, tile);
}

// take the object from the tile
void take_resource(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "food") == 0) {
        if (tile->food > 0) {
            tile->food--;
            client->inventory->food++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    if (strcmp(resource, "linemate") == 0) {
        if (tile->linemate > 0) {
            tile->linemate--;
            client->inventory->linemate++;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    take_resource2(client, resource, tile);
}

// get the id of an object
static int get_object_id(char *resource)
{
    if (strcmp(resource, "food") == 0)
        return 0;
    if (strcmp(resource, "linemate") == 0)
        return 1;
    if (strcmp(resource, "deraumere") == 0)
        return 2;
    if (strcmp(resource, "sibur") == 0)
        return 3;
    if (strcmp(resource, "mendiane") == 0)
        return 4;
    if (strcmp(resource, "phiras") == 0)
        return 5;
    if (strcmp(resource, "thystame") == 0)
        return 6;
    return 0;
}

// remove the object from the tile and add it to the player inventory
static void make_take_object(client_t *client, char *cmd, server_t *server)
{
    tile_t *tile;
    int id = 0;

    (void)cmd;
    tile = &server->serverConfig->map->tiles[client->y][client->x];
    if (verif_ressource(client->set_object_cmd) == 0) {
        send(client->socket, "ko\n", 3, 0);
        return;
    }
    take_resource(client, client->take_object_cmd, tile);
    id = get_object_id(client->take_object_cmd);
    cmd_pgt(server, client->id, id);
}

// send the take object command
void send_take_object(client_t *client, char *cmd, server_t *server)
{
    if (client->is_take_object == 1) {
        make_take_object(client, cmd, server);
        client->is_take_object = 0;
        client->request_action = 0;
    }
}

// take object command
void cmd_take_object(client_t *client, char *cmd)
{
    client->is_take_object = 1;
    client->action = 7;
    client->take_object_cmd = strdup(cmd + 5);
}
