/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_ppo
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// ppo command received from the gui
void command_ppo(server_t *server, char *buffer)
{
    char *tmp;
    int player_id;
    player_t player;
    client_t *client;

    tmp = buffer + 4;
    player_id = atoi(tmp);
    write_log_file("received ppo from gui\n");
    if (get_player_by_id(server, player_id) == NULL)
        return;
    client = get_player_by_id(server, player_id);
    player.player_id = client->id;
    player.x = client->x;
    player.y = client->y;
    player.orientation = client->orientation;
    player.level = client->level;
    player.team_name = client->team_name;
    cmd_ppo(server, &player);
}
