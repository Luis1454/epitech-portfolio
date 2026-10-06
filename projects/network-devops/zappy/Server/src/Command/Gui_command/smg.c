/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** smg
*/

#include "../../../include/Command/gui_command.h"

// message from the server
void cmd_smg(server_t *server, char *message)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "smg %s\n", message);
}
