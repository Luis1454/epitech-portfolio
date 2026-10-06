/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dl
*/

#include "Dl.hpp"
#include <iostream>

void *dl::my_dl_open(const char *path) {
    return ::dl_open(path);
}

void *dl::my_dl_sym(void *handle, const char *name) {
    return ::dl_sym(handle, name);
}

void *dl::my_dl_close(void *handle) {
    return ::dl_close(handle);
}

std::string dl::my_dl_error() {
    return ::dl_error();
}
