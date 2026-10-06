/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Clamp
*/

#include "../../include/Effects/Clamp.hpp"

Clamp::Clamp()
{
}

Clamp::~Clamp()
{
}

void Clamp::applyEffect(Image &img)
{
    for (size_t i = 0; i < img.size(); i++)
        for (size_t j = 0; j < img[i].size(); j++) {
            img[i][j].setR(std::min(1.0, std::max(0.0, img[i][j].getR())));
            img[i][j].setG(std::min(1.0, std::max(0.0, img[i][j].getG())));
            img[i][j].setB(std::min(1.0, std::max(0.0, img[i][j].getB())));
    }
}
