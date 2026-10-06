/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** incantation
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// check if the player can be elevated 3
static bool condition_to_elevation3(client_t *client, server_t *server)
{
    if (client->level == 6 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 6 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].deraumere >= 2
        && server->serverConfig->map->tiles[client->y][client->x].sibur >= 3 &&
        server->serverConfig->map->tiles[client->y][client->x].phiras >= 1)
        return true;
    if (client->level == 7 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 6 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].deraumere >= 2
        && server->serverConfig->map->tiles[client->y][client->x].sibur >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].mendiane >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].phiras >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].thystame >= 1)
        return true;
    return false;
}

// check if the player can be elevated 2
static bool condition_to_elevation2(client_t *client, server_t *server)
{
    if (client->level == 4 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 4 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].deraumere >= 1
        && server->serverConfig->map->tiles[client->y][client->x].sibur >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].phiras >= 1)
        return true;
    if (client->level == 5 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 4 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].deraumere >= 2
        && server->serverConfig->map->tiles[client->y][client->x].sibur >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].mendiane >= 3)
        return true;
    return condition_to_elevation3(client, server);
}

// check if the player can be elevated
bool condition_to_elevation(client_t *client, server_t *server)
{
    if (client->level == 1 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 1)
        return true;
    if (client->level == 2 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].deraumere >= 1
        && server->serverConfig->map->tiles[client->y][client->x].sibur >= 1)
            return true;
    if (client->level == 3 &&
        server->serverConfig->map->tiles[client->y][client->x].player >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].linemate >= 2 &&
        server->serverConfig->map->tiles[client->y][client->x].sibur >= 1 &&
        server->serverConfig->map->tiles[client->y][client->x].phiras >= 2)
        return true;
    return condition_to_elevation2(client, server);
}
