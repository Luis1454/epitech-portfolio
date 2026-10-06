/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** main
*/

#include "../include/Parsing/parsing.h"
#include "../include/include.h"
#include "../include/Server/server.h"
#include "../include/Server/init.h"

int main(int ac, char *av[])
{
    server_t server;
    int ret;

    ret = 0;
    server.start_game = false;
    srand(time(NULL));
    server.serverConfig = malloc(sizeof(serverConfig_t));
    ret = get_param(ac, av, server.serverConfig);
    if (ret != 0)
        return ret == 1 ? 0 : 84;
    init_server(&server);
    print_world_info(server.serverConfig);
    run_server(&server);
    return 0;
}
