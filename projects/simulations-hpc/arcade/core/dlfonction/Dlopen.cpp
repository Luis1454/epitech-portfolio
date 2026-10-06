/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dlopen
*/

#include "Dl.h"

void *dl_open(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle)
        return NULL;
    return handle;
}
