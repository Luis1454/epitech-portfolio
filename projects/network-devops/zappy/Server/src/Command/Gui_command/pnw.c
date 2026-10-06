/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pnw
*/

#include "../../../include/Command/gui_command.h"

// connection of a new player
void cmd_pnw(server_t *server, player_t *new_player)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true) {
            dprintf(server->clients[i].socket, "pnw %d %d %d %d %d %s\n",
            new_player->player_id, new_player->x, new_player->y,
            new_player->orientation, new_player->level,
            new_player->team_name);
        }
}
