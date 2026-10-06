/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_sst
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// sst command received from the gui
void command_sst(server_t *server, char *buffer)
{
    char *tmp;
    int time;

    tmp = buffer + 4;
    write_log_file("received sst from gui\n");
    time = atoi(tmp);
    server->serverConfig->frequence = time;
    cmd_sst(server);
}
