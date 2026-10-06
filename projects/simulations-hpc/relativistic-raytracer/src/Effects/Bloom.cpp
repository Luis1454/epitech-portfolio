/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Bloom
*/

#include "../../include/Effects/Bloom.hpp"
#include "../../include/Effects/Clamp.hpp"
#include "../../include/Effects/GaussianBlur.hpp"
#include "../../include/Parser/RecupEffect.hpp"

Bloom::Bloom(std::unique_ptr<Effect> imageEffect, double threshold, double sigma, int radius)
{
    _imageEffect = std::move(imageEffect);
    _threshold = threshold;
    _sigma = sigma;
    _radius = radius;
}

void Bloom::applyEffect(Image &img)
{
    Image mask(img.size(), std::vector<Color>(img[0].size()));
    Clamp clamp;
    GaussianBlur gaussianBlur(std::move(_imageEffect), _sigma, _radius);

    for (size_t i = 0; i < img.size(); i++)
        for (size_t j = 0; j < img[i].size(); j++) {
            double brightness = img[i][j].getR() + img[i][j].getG() + img[i][j].getB() / 3.0;
            if (brightness > _threshold)
                mask[i][j] = img[i][j];
            else
                mask[i][j] = Color(0.0, 0.0, 0.0);
        }
    gaussianBlur.applyEffect(mask);
    for (size_t i = 0; i < img.size(); i++)
        for (size_t j = 0; j < img[i].size(); j++)
            img[i][j] += mask[i][j];
    clamp.applyEffect(img);
}
