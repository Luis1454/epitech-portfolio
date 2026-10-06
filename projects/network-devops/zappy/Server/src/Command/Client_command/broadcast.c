/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** broadcast
*/

#include "../../../include/Command/gui_command.h"
#include "../../../include/Command/client_command.h"

// take the direction were the message come from
static int take_direction(int direction, client_t *receiver,
    int dx, int dy)
{
    switch (receiver->orientation) {
        case 1:
            direction = est_direction(dx, dy);
            break;
        case 2:
            direction = sud_direction(dx, dy);
            break;
        case 3:
            direction = ouest_direction(dx, dy);
            break;
        case 4:
            direction = nord_direction(dx, dy);
            break;
        default:
            break;
    }
    return direction;
}

// calculate the direction
static int calculate_direction(client_t *emitter, client_t *receiver,
    int map_width, int map_height)
{
    int dx = receiver->x - emitter->x;
    int dy = receiver->y - emitter->y;
    int direction = 0;

    if (dx == 0 && dy == 0)
        return 0;
    if (dx > map_width / 2)
        dx -= map_width;
    if (dx < -map_width / 2)
        dx += map_width;
    if (dy > map_height / 2)
        dy -= map_height;
    if (dy < -map_height / 2)
        dy += map_height;
    direction = take_direction(direction, receiver, dx, dy);
    return direction;
}

int check_direction(int direction)
{
    if (direction == 1)
        return 5;
    if (direction == 2)
        return 6;
    if (direction == 3)
        return 7;
    if (direction == 4)
        return 8;
    if (direction == 5)
        return 1;
    if (direction == 6)
        return 2;
    if (direction == 7)
        return 3;
    if (direction == 8)
        return 4;
    return 0;
}

// broadcast the action
void broadcast_action(client_t *client, server_t *server, char *cmd)
{
    int direction = -1;
    client_t *receiver;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_connected == false ||
        server->clients[i].is_gui == true)
            continue;
        receiver = &server->clients[i];
        if (receiver->is_connected && receiver->socket != client->socket) {
            direction = calculate_direction(client, receiver,
            server->serverConfig->map_width, server->serverConfig->map_height);
            direction = check_direction(direction);
            send_message_broadcast(direction, cmd, receiver);
        }
    }
    cmd_pbc(server, client->id, cmd);
}

// make the broadcast command
void make_broadcast(client_t *client, char *cmd, server_t *server)
{
    const char *prefix = "Broadcast ";
    int prefix_len = strlen(prefix);
    char *msg;

    (void) cmd;
    if (strncmp(client->broadcast_cmd, prefix, prefix_len) != 0) {
        send(client->socket, "ko\n", 3, 0);
        return;
    }
    msg = client->broadcast_cmd + prefix_len;
    broadcast_action(client, server, msg);
    send(client->socket, "ok\n", 3, 0);
}

// send the broadcast command
void send_broadcast(client_t *client, char *cmd, server_t *server)
{
    if (client->is_broadcast == 1) {
        make_broadcast(client, cmd, server);
        client->is_broadcast = 0;
        client->request_action = 0;
    }
}

// broadcast command
void cmd_broadcast(client_t *client, char *cmd)
{
    client->is_broadcast = 1;
    client->action = 7;
    client->broadcast_cmd = strdup(cmd);
}
