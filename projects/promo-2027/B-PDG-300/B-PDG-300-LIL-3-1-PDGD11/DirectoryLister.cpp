/*
** EPITECH PROJECT, 2024
** DirectoryLister.hpp
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister(const std::string &path,
bool hidden) : _dir(nullptr), _hidden(hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (_dir != NULL)
        closedir(_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    DIR *dir = opendir(path.c_str());

    _hidden = false;
    if (dir == NULL) {
        perror(path.c_str());
        if (_dir != NULL)
            closedir(_dir);
        _dir = NULL;
        return false;
    }
    if (_dir != NULL)
        closedir(_dir);
    _dir = dir;
    _hidden = hidden;
    return true;
}

std::string DirectoryLister::get()
{
    struct dirent *d = NULL;

    if (_dir == NULL)
        return std::string();
    d = readdir(_dir);
    if (d == NULL)
        return std::string();
    if (!_hidden && d->d_name[0] == '.')
        return get();
    return std::string(d->d_name);
}
