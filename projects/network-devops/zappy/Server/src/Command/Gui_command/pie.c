/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pie
*/

#include "../../../include/Command/gui_command.h"

// end of an incantation
void cmd_pie(server_t *server, incantation_t *incantation)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true)
            dprintf(server->clients[i].socket, "pie %d %d %d\n",
            incantation->x, incantation->y, incantation->result);
}
