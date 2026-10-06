/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** inventory
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// send inventory to gui
void send_inventory_gui(client_t *client, server_t *server)
{
    player_inventory_t inv;

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

// make inventory
static void make_inventory(client_t *client, char *cmd, server_t *server)
{
    char *str;

    (void)cmd;
    (void)server;
    str = malloc(sizeof(char) * 1000);
    if (str == NULL)
        exit(84);
    snprintf(str, 1000, "[ food %d, linemate %d, deraumere %d",
    client->inventory->food, client->inventory->linemate,
    client->inventory->deraumere);
    snprintf(str + strlen(str), 1000, ", sibur %d, mendiane %d,",
    client->inventory->sibur, client->inventory->mendiane);
    snprintf(str + strlen(str), 1000, " phiras %d, thystame %d ]\n",
    client->inventory->phiras, client->inventory->thystame);
    send(client->socket, str, strlen(str), 0);
    free(str);
    send_inventory_gui(client, server);
}

// send inventory to client
void send_inventory(client_t *client, char *cmd, server_t *server)
{
    if (client->is_inventory == 1) {
        make_inventory(client, cmd, server);
        client->is_inventory = 0;
        client->request_action = 0;
    }
}

// inventory command
void cmd_inventory(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_inventory = 1;
    client->action = 7;
}
