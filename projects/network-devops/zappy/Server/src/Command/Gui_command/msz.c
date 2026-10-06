/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** msz
*/

#include "../../../include/Command/gui_command.h"

// map size
void cmd_msz(server_t *server)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "msz %d %d\n",
                server->serverConfig->map_width,
                server->serverConfig->map_height);
}
