/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pdi
*/

#include "../../../include/Command/gui_command.h"

// death of a player
void cmd_pdi(server_t *server, int player_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pdi %d\n", player_id);
}
