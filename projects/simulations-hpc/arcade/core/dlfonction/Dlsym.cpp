/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dlsym
*/

#include "Dl.h"

void *dl_sym(void *handle, const char *name)
{
    void *ptr = dlsym(handle, name);
    if (!ptr)
        return NULL;
    return ptr;
}
