/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** seg
*/

#include "../../../include/Command/gui_command.h"

// end of the game
void cmd_seg(server_t *server, char *message)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "seg %s\n", message);
}
