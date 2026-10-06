/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pfk
*/

#include "../../../include/Command/gui_command.h"

// egg laying of a player
void cmd_pfk(server_t *server, int player_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pfk %d\n", player_id);
}
