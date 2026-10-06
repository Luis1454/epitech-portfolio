/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** set_object
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// list of resources 4
static void set_resource4(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "thystame") == 0) {
        if (client->inventory->thystame > 0) {
            tile->thystame++;
            client->inventory->thystame--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
    } else
        send(client->socket, "ko\n", 3, 0);
}

// list of resources 3
static void set_resource3(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "mendiane") == 0) {
        if (client->inventory->mendiane > 0) {
            tile->mendiane++;
            client->inventory->mendiane--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    if (strcmp(resource, "phiras") == 0) {
        if (client->inventory->phiras > 0) {
            tile->phiras++;
            client->inventory->phiras--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    set_resource4(client, resource, tile);
}

// list of resources 2
static void set_resource2(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "deraumere") == 0) {
        if (client->inventory->deraumere > 0) {
            tile->deraumere++;
            client->inventory->deraumere--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    if (strcmp(resource, "sibur") == 0) {
        if (client->inventory->sibur > 0) {
            tile->sibur++;
            client->inventory->sibur--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    set_resource3(client, resource, tile);
}

// list of resources
static void set_resource(client_t *client,
    char *resource, tile_t *tile)
{
    if (strcmp(resource, "food") == 0) {
        if (client->inventory->food > 0) {
            tile->food++;
            client->inventory->food--;
            send(client->socket, "ok\n", 3, 0);
        } else {
            send(client->socket, "ko\n", 3, 0);
        }
        return;
    }
    if (strcmp(resource, "linemate") == 0) {
        if (client->inventory->linemate > 0) {
            tile->linemate++;
            client->inventory->linemate--;
            send(client->socket, "ok\n", 3, 0);
        } else
            send(client->socket, "ko\n", 3, 0);
        return;
    }
    set_resource2(client, resource, tile);
}

// check if the resource is valid
int verif_ressource(char *cmd)
{
    if (cmd == NULL)
        return 1;
    if (strcmp(cmd, "food") == 0)
        return 1;
    if (strcmp(cmd, "linemate") == 0)
        return 1;
    if (strcmp(cmd, "deraumere") == 0)
        return 1;
    if (strcmp(cmd, "sibur") == 0)
        return 1;
    if (strcmp(cmd, "mendiane") == 0)
        return 1;
    if (strcmp(cmd, "phiras") == 0)
        return 1;
    if (strcmp(cmd, "thystame") == 0)
        return 1;
    return 0;
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

// set the resource on the tile and remove it from the inventory
static void make_set_object(client_t *client, char *cmd, server_t *server)
{
    tile_t *tile;

    (void)cmd;
    tile = &server->serverConfig->map->tiles[client->y][client->x];
    if (verif_ressource(client->set_object_cmd) == 0) {
        send(client->socket, "ko\n", 3, 0);
        return;
    }
    set_resource(client, client->set_object_cmd, tile);
    cmd_pdr(server, client->id, get_object_id(client->set_object_cmd));
}

// send the set object to the client
void send_set_object(client_t *client, char *cmd, server_t *server)
{
    if (client->is_set_object == 1) {
        make_set_object(client, cmd, server);
        client->is_set_object = 0;
        client->request_action = 0;
    }
}

// set object command
void cmd_set_object(client_t *client, char *cmd)
{
    client->is_set_object = 1;
    client->action = 7;
    client->set_object_cmd = strdup(cmd + 4);
}
