/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** left
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"

// client left action command
void left_action(client_t *client)
{
    if (client->orientation == 1)
        client->orientation = 4;
    else
        client->orientation--;
}

static void make_left(client_t *client, char *cmd, server_t *server)
{
    player_t player;

    (void)cmd;
    (void)server;
    left_action(client);
    player.player_id = client->id;
    player.x = client->x;
    player.y = client->y;
    player.orientation = client->orientation;
    player.level = client->level;
    player.team_name = client->team_name;
    cmd_ppo(server, &player);
    send(client->socket, "ok\n", 3, 0);
}

void send_left(client_t *client, char *cmd, server_t *server)
{
    if (client->is_left == 1) {
        make_left(client, cmd, server);
        client->is_left = 0;
        client->request_action = 0;
    }
}

void cmd_left(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_left = 1;
    client->action = 7;
}
