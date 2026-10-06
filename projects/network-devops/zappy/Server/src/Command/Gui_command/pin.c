/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pin
*/

#include "../../../include/Command/gui_command.h"

// player’s inventory
void cmd_pin(server_t *server, player_inventory_t *player_inventory)
{
    for (int i = 0; i < server->clients_nbr; i++)
        if (server->clients[i].is_gui == true) {
            dprintf(server->clients[i].socket,
            "pin %d %d %d %d %d %d %d %d %d %d\n",
            player_inventory->player_id, player_inventory->x,
            player_inventory->y, player_inventory->food,
            player_inventory->linemate, player_inventory->deraumere,
            player_inventory->sibur, player_inventory->mendiane,
            player_inventory->phiras, player_inventory->thystame);
        }
}
