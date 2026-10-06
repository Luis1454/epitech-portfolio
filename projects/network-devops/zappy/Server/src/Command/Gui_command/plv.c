/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** plv
*/

#include "../../../include/Command/gui_command.h"

// player level
void cmd_plv(server_t *server, int player_id, int level)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "plv %d %d\n",
                player_id, level);
}
