/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_bct
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// bct command received from the gui
void command_bct(server_t *server, char *buffer, int client)
{
    int i = 0;
    int j = 0;
    char *tmp;

    write_log_file("received bct from gui with args : %s\n", buffer);
    tmp = buffer + 4;
    i = atoi(tmp);
    while (*tmp != ' ')
        tmp++;
    j = atoi(tmp);
    dprintf(server->clients[client].socket,
        "bct %d %d %d %d %d %d %d %d %d\n",
        i, j, server->serverConfig->map->tiles[j][i].linemate,
        server->serverConfig->map->tiles[j][i].deraumere,
        server->serverConfig->map->tiles[j][i].sibur,
        server->serverConfig->map->tiles[j][i].mendiane,
        server->serverConfig->map->tiles[i][i].phiras,
        server->serverConfig->map->tiles[j][i].thystame,
        server->serverConfig->map->tiles[j][i].food);
}
