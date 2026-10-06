/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_pin
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// pin command received from the gui
void command_pin(server_t *server, char *buffer)
{
    int player_id;
    player_inventory_t inv;
    client_t *client;

    player_id = atoi(buffer + 4);
    write_log_file("received pin from gui\n");
    client = get_player_by_id(server, player_id);
    if (client == NULL)
        return;
    inv.player_id = client->id;
    inv.x = client->x;
    inv.y = client->y;
    inv.food = client->inventory->food;
    inv.linemate = client->inventory->linemate;
    inv.deraumere = client->inventory->deraumere;
    inv.sibur = client->inventory->sibur;
    inv.mendiane = client->inventory->mendiane;
    inv.phiras = client->inventory->phiras;
    inv.thystame = client->inventory->thystame;
    cmd_pin(server, &inv);
}
