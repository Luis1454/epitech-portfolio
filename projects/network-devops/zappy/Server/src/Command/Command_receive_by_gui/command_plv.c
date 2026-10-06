/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_plv
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// plv command received from the gui
void command_plv(server_t *server, char *buffer)
{
    int player_id;
    int level;
    client_t *client;

    write_log_file("received plv from gui\n");
    player_id = atoi(buffer + 4);
    client = get_player_by_id(server, player_id);
    if (client == NULL)
        return;
    level = client->level;
    cmd_plv(server, player_id, level);
}
