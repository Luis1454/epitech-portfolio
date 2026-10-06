/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ParsingArg
*/

#include "../../include/Parsing/parsing.h"

// return 0 if the string is a number
static int is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return ERROR;
    return SUCCESS;
}

// verify if the argument is correct
static int handle_argument(char *value, int error_code, int *destination)
{
    if (!value || is_number(value) == ERROR)
        return error(error_code);
    if (error_code == ERROR_FREQUENCE && (atoi(value) < 2 ||
        atoi(value) > 10000))
        return error(ERROR_FREQUENCE_RANGE);
    *destination = atoi(value);
    return SUCCESS;
}

// init serverConfig structure
static void init_data(serverConfig_t *serverConfig)
{
    serverConfig->port_nb = 0;
    serverConfig->map_width = 0;
    serverConfig->map_height = 0;
    serverConfig->client_nb = 0;
    serverConfig->frequence = 100;
    serverConfig->teams_nb = 0;
}

// get the ip address of the server (not localhost)
static char *get_ip(void)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;
    char *ip = NULL;

    if (getifaddrs(&ifaddr) == -1)
        return NULL;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET
            && strcmp(ifa->ifa_name, "lo") != 0) {
            ip = strdup(inet_ntoa(((struct sockaddr_in *)
            ifa->ifa_addr)->sin_addr));
            break;
        }
    }
    freeifaddrs(ifaddr);
    return ip;
}

// recup the teams names from the arguments
int recup_teams_names(int i, int ac, char *av[], serverConfig_t *serverConfig)
{
    serverConfig->teams = malloc(sizeof(char *) * (ac));
    if (!serverConfig->teams)
        return ERROR;
    for (int j = 0; j < ac - i - 1 && av[i + j + 1][0] != '-'; j++) {
        serverConfig->teams[j].name = strdup(av[i + j + 1]);
        if (!serverConfig->teams[j].name)
            return ERROR;
        serverConfig->teams_nb++;
    }
    return SUCCESS;
}

// recup the arguments from the command line
int recup_argument(int i, int ac, char *av[], serverConfig_t *Conf)
{
    if (strcmp(av[i], "-p") == 0)
        return handle_argument(av[i + 1], ERROR_PORT, &Conf->port_nb);
    if (strcmp(av[i], "-x") == 0)
        return handle_argument(av[i + 1], ERROR_WIDTH, &Conf->map_width);
    if (strcmp(av[i], "-y") == 0)
        return handle_argument(av[i + 1], ERROR_HEIGHT, &Conf->map_height);
    if (strcmp(av[i], "-n") == 0) {
        if (i + 1 >= ac)
            return error(ERROR_TEAM_NAME);
        return recup_teams_names(i, ac, av, Conf);
    }
    if (strcmp(av[i], "-c") == 0)
        return handle_argument(av[i + 1], ERROR_CLIENT_NB, &Conf->client_nb);
    if (strcmp(av[i], "-f") == 0)
        return handle_argument(av[i + 1], ERROR_FREQUENCE, &Conf->frequence);
    return SUCCESS;
}

// fonction to recup the arguments from the command line
int get_param(int ac, char *av[], serverConfig_t *serverConfig)
{
    int i = 1;

    init_data(serverConfig);
    for (; i < ac; i++) {
        if (strcmp(av[i], "-h") == 0)
            return print_usage();
        if (recup_argument(i, ac, av, serverConfig) == 84)
            return 84;
    }
    if (serverConfig->port_nb == 0 || serverConfig->map_width == 0 ||
    serverConfig->map_height == 0 || serverConfig->teams_nb == 0 ||
    serverConfig->client_nb == 0)
        return error(ERROR_ENOUGH_ARGS);
    serverConfig->ip = get_ip();
    return 0;
}
