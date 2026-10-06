/*
** EPITECH PROJECT, 2024
** DirectoryLister.hpp
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_

#include <dirent.h>
#include <iostream>
#include <cstring>

#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister() : _dir(nullptr), _hidden(false) {}
        DirectoryLister(const std::string &path, bool hidden);
        ~DirectoryLister();
        bool open(const std::string &path, bool hidden);
        std::string get();
    protected:
        DIR *_dir;
        bool _hidden;
};

#endif /* !DIRECTORYLISTER_HPP_ */
