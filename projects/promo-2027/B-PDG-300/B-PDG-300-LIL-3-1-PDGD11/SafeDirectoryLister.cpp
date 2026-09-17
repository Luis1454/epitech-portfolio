/*
** EPITECH PROJECT, 2024
** SafeDirectoryLister.cpp
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"
#include <cstring>

SafeDirectoryLister::SafeDirectoryLister(const std::string &path,
bool hidden) : _dir(nullptr), _hidden(hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (_dir != NULL)
        closedir(_dir);
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden)
{
    DIR* dir = opendir(path.c_str());

    if (dir == nullptr)
        throw OpenFailureException(strerror(errno));
    if (_dir != nullptr)
        closedir(_dir);
    _dir = dir;
    _hidden = hidden;
    return true;
}


std::string SafeDirectoryLister::get()
{
    struct dirent* d = nullptr;

    if (_dir == nullptr)
        throw NoMoreFileException();
    d = readdir(_dir);
    if (d == nullptr)
        throw NoMoreFileException();
    if (!_hidden && d->d_name[0] == '.')
        return get();
    return std::string(d->d_name);
}
