/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** unknown
*/

#include "../../../include/Command/client_command.h"

void cmd_unknown(client_t *client, char *cmd)
{
    (void)cmd;
    dprintf(client->socket, "ko\n");
}
