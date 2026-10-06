/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pbc
*/

#include "../../../include/Command/gui_command.h"

// broadcast text
void cmd_pbc(server_t *server, int player_id, char *message)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
        dprintf(server->clients[i].socket, "pbc %d %s\n", player_id, message);
}
