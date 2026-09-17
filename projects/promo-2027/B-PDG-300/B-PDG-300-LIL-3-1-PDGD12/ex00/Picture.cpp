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
