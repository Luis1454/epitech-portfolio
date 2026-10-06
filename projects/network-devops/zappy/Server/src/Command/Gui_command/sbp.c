/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** sbp
*/

#include "../../../include/Command/gui_command.h"

// command parameter
void cmd_sbp(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "sbp\n");
}
