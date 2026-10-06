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
        Picture(const std::string &file);
        ~Picture(){}
        std::string data;
        bool getPictureFromFile(const std::string &file);
};

#endif /* !PICTURE_HPP_ */
