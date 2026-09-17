/*
** EPITECH PROJECT, 2024
** SafeDirectoryLister.hpp
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_

#include <iostream>
#include <dirent.h>
#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister() : _dir(nullptr), _hidden(false) {}
        SafeDirectoryLister(const std::string &path, bool hidden);
        ~SafeDirectoryLister();

        bool open(const std::string &path, bool hidden);
        std::string get();

    protected:
        DIR *_dir;
        bool _hidden;
};

#endif //SAFEDIRECTORYLISTER_HPP_
