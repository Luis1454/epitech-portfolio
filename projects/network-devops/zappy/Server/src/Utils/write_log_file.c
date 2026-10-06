/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** write_log_file
*/

#include "../../include/Utils/utils.h"

// Write in the server.log file, work like printf
void write_log_file(char *str, ...)
{
    FILE *file = fopen("server.log", "a");
    va_list args;

    if (file == NULL) {
        perror("fopen");
        exit(84);
    }
    va_start(args, str);
    vfprintf(file, str, args);
    va_end(args);
    fclose(file);
}
