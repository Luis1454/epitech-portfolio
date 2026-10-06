/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_msz
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// msz command received from the gui
void command_msz(server_t *server, char *buffer)
{
    (void)buffer;
    write_log_file("received msz from gui\n");
    cmd_msz(server);
}
