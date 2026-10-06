/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** broadcast_second
*/

#include "../../../include/Command/gui_command.h"
#include "../../../include/Command/client_command.h"

// send the message to the client
void send_message_broadcast(int direction,
    char *cmd, client_t *receiver)
{
    char buffer[BUFFER_SIZE];

    if (direction == 0)
        snprintf(buffer, BUFFER_SIZE, "message 0, %s\n", cmd);
    else
        snprintf(buffer, BUFFER_SIZE, "message %d, %s\n", direction, cmd);
    send(receiver->socket, buffer, strlen(buffer), 0);
}

// determinate the east direction
int est_direction(int dx, int dy)
{
    if (dx > 0 && dy == 0)
        return 1;
    if (dx > 0 && dy < 0)
        return 2;
    if (dx == 0 && dy < 0)
        return 3;
    if (dx < 0 && dy < 0)
        return 4;
    if (dx < 0 && dy == 0)
        return 5;
    if (dx < 0 && dy > 0)
        return 6;
    if (dx == 0 && dy > 0)
        return 7;
    if (dx > 0 && dy > 0)
        return 8;
    return 0;
}

// determinate the south direction
int sud_direction(int dx, int dy)
{
    if (dy > 0 && dx == 0)
        return 1;
    if (dy > 0 && dx > 0)
        return 2;
    if (dx > 0 && dy == 0)
        return 3;
    if (dx > 0 && dy < 0)
        return 4;
    if (dy < 0 && dx == 0)
        return 5;
    if (dy < 0 && dx < 0)
        return 6;
    if (dx < 0 && dy == 0)
        return 7;
    if (dx < 0 && dy > 0)
        return 8;
    return 0;
}

// determinate the west direction
int ouest_direction(int dx, int dy)
{
    if (dx < 0 && dy == 0)
        return 1;
    if (dx < 0 && dy > 0)
        return 2;
    if (dy > 0 && dx == 0)
        return 3;
    if (dy > 0 && dx > 0)
        return 4;
    if (dx > 0 && dy == 0)
        return 5;
    if (dx > 0 && dy < 0)
        return 6;
    if (dy < 0 && dx == 0)
        return 7;
    if (dx < 0 && dy < 0)
        return 8;
    return 0;
}

// determinate the north direction
int nord_direction(int dx, int dy)
{
    if (dy < 0 && dx == 0)
        return 1;
    if (dy < 0 && dx < 0)
        return 2;
    if (dx < 0 && dy == 0)
        return 3;
    if (dx < 0 && dy > 0)
        return 4;
    if (dy > 0 && dx == 0)
        return 5;
    if (dy > 0 && dx > 0)
        return 6;
    if (dx > 0 && dy == 0)
        return 7;
    if (dy < 0 && dx > 0)
        return 8;
    return 0;
}
