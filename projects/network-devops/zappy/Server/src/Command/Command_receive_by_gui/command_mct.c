/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_mct
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// mct command received from the gui
void command_mct(server_t *server, char *buffer)
{
    (void)buffer;
    write_log_file("received mct from gui\n");
    cmd_bct(server);
}
