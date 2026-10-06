/*
** EPITECH PROJECT, 2024
** Picture.cpp
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>

Picture::Picture()
{
    data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::Picture(const char *file)
{
    getPictureFromFile(file);
}

Picture::Picture(const Picture &picture)
{
    data = picture.data;
}

Picture &Picture::operator=(const Picture &picture)
{
    data = picture.data;
    return *this;
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream ifs(file);
    std::string line;

    if (!ifs.is_open()) {
        data = "ERROR";
        return false;
    }
    data = "";
    while (getline(ifs, line))
        data += line + "\n";
    return true;
}
