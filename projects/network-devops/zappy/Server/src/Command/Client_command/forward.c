/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** forward
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// move the player to the case forward
void forward_action(client_t *client, server_t *server)
{
    if (client->orientation == 1)
        client->x++;
    if (client->orientation == 2)
        client->y++;
    if (client->orientation == 3)
        client->x--;
    if (client->orientation == 4)
        client->y--;
    if (client->x >= server->serverConfig->map_width)
        client->x = 0;
    else if (client->x < 0)
        client->x = server->serverConfig->map_width - 1;
    if (client->y >= server->serverConfig->map_height)
        client->y = 0;
    else if (client->y < 0)
        client->y = server->serverConfig->map_height - 1;
    server->serverConfig->map->tiles[client->y][client->x].player++;
}

static void make_forward(client_t *client, char *cmd, server_t *server)
{
    player_t player;

    (void)cmd;
    if (server->serverConfig->map->tiles[client->y][client->x].player > 0)
        server->serverConfig->map->tiles[client->y][client->x].player--;
    forward_action(client, server);
    send(client->socket, "ok\n", 3, 0);
    player.player_id = client->id;
    player.x = client->x;
    player.y = client->y;
    player.orientation = client->orientation;
    cmd_ppo(server, &player);
}

void send_forward(client_t *client, char *cmd, server_t *server)
{
    if (client->is_forward == 1) {
        client->is_forward = 0;
        make_forward(client, cmd, server);
        client->request_action = 0;
    }
}

void cmd_forward(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_forward = 1;
    client->action = 7;
}
