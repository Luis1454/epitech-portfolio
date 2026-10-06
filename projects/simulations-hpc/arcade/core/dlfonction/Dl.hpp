/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dl
*/

#ifndef DL_HPP_
    #define DL_HPP_

#include <iostream>
#include "Dl.h"

class dl {
    public:
        static void *my_dl_open(const char *path);
        static void *my_dl_sym(void *handle, const char *name);
        static void *my_dl_close(void *handle);
        static std::string my_dl_error();
};

#endif /* !DL_HPP_ */
