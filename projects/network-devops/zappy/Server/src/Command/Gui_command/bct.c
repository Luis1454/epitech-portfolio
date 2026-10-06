/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** bct
*/

#include "../../../include/Command/gui_command.h"

// for (int i = 0; i < server->serverConfig->map_height; i++) {
//         for (int j = 0; j < server->serverConfig->map_width; j++) {
void cmd_bct_two(server_t *server, int client)
{
    for (int i = 0; i < server->serverConfig->map_height; i++) {
        for (int j = 0; j < server->serverConfig->map_width; j++) {
            dprintf(server->clients[client].socket,
                "bct %d %d %d %d %d %d %d %d %d\n",
                j, i, server->serverConfig->map->tiles[i][j].food,
                server->serverConfig->map->tiles[i][j].linemate,
                server->serverConfig->map->tiles[i][j].deraumere,
                server->serverConfig->map->tiles[i][j].sibur,
                server->serverConfig->map->tiles[i][j].mendiane,
                server->serverConfig->map->tiles[i][j].phiras,
                server->serverConfig->map->tiles[i][j].thystame);
        }
    }
}

// tile content
void cmd_bct(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            cmd_bct_two(server, i);
}
