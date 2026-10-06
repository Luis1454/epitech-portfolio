/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dlclose
*/

#include "Dl.h"

void *dl_close(void *handle)
{
    if (dlclose(handle) != 0)
        return NULL;
    return handle;
}
