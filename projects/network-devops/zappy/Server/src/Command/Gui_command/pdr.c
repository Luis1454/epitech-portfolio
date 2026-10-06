/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pdr
*/

#include "../../../include/Command/gui_command.h"

// resource dropping
void cmd_pdr(server_t *server, int player_id, int resource_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pdr %d %d\n",
            player_id, resource_id);
}
