/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** error
*/

#include "../../include/Parsing/error.h"

// List of error messages for parsing
const char *error_messages[9] = {
    [ERROR_PORT] = "Error: invalid port number\n",
    [ERROR_WIDTH] = "Error: invalid width\n",
    [ERROR_HEIGHT] = "Error: invalid height\n",
    [ERROR_TEAM_NAME] = "Error: invalid team name\n",
    [ERROR_CLIENT_NB] = "Error: invalid client number\n",
    [ERROR_FREQUENCE] = "Error: invalid frequence\n",
    [ERROR_ENOUGH_ARGS] = "Error: not enough arguments Need at least:\n\
    -p, -x, -y, -n, -c\n",
    [ERROR_FREQUENCE_RANGE] = "Error: frequence must be between 2 and 10000\n",
};

// Print error message according to error code
int error(int err)
{
    if (err >= 0 && err < 9 && error_messages[err])
        printf("%s", error_messages[err]);
    else
        printf("Error: unknown error code\n");
    return 84;
}
