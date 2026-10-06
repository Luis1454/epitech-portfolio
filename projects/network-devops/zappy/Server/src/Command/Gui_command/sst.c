/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** sst
*/

#include "../../../include/Command/gui_command.h"

// time unit modification
void cmd_sst(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "sst %d\n",
                server->serverConfig->frequence);
}
