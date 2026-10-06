/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** edi
*/

#include "../../../include/Command/gui_command.h"

// death of an egg
void cmd_edi(server_t *server, int egg_id)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "edi %d\n", egg_id);
}
