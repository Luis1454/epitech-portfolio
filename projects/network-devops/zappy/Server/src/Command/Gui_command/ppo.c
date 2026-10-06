/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ppo
*/

#include "../../../include/Command/gui_command.h"

// define the orientation
int define_orientation(player_t *player, int orientation)
{
    if (player->orientation == 1 || player->orientation == 3)
        orientation = player->orientation + 1;
    if (player->orientation == 2)
        orientation = 1;
    if (player->orientation == 4)
        orientation = 3;
    return orientation;
}

// player position
void cmd_ppo(server_t *server, player_t *player)
{
    int orientation = 0;

    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true) {
            orientation = define_orientation(player, orientation);
            dprintf(server->clients[i].socket, "ppo %d %d %d %d\n",
            player->player_id, player->x, player->y, orientation);
        }
}
