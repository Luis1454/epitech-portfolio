/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** enw
*/

#include "../../../include/Command/gui_command.h"

// an egg was laid by a player
void cmd_enw(server_t *server, egg_t egg)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "enw %d %d %d %d\n", egg.egg_id,
                egg.player_id, egg.x, egg.y);
}
