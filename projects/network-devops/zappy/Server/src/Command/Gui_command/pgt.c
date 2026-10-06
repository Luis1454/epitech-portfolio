/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pgt
*/

#include "../../../include/Command/gui_command.h"

// resource collecting
void cmd_pgt(server_t *server, int player_id, int resource_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pgt %d %d\n",
            player_id, resource_id);
}
