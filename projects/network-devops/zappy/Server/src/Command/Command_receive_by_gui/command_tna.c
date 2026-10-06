/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_tna
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// tna command received from the gui
void command_tna(server_t *server, char *buffer)
{
    (void)buffer;
    write_log_file("received tna from gui\n");
    cmd_tna(server);
}
