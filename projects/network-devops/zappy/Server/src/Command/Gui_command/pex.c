/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pex
*/

#include "../../../include/Command/gui_command.h"

// expulsion of a player
void cmd_pex(server_t *server, int player_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pex %d\n", player_id);
}
