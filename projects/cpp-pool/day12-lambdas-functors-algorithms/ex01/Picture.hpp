/*
** EPITECH PROJECT, 2024
** Picture.hpp
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>

class Picture {
    public:
        Picture();
        Picture(const Picture &picture);
        Picture(const std::string &file);
        Picture(const char *file);
        ~Picture(){}

        Picture &operator=(const Picture &picture);

        bool getPictureFromFile(const std::string &file);
        std::string data;
};

#endif /* !PICTURE_HPP_ */
