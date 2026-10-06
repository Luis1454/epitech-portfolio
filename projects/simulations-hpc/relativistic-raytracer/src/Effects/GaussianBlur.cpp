/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** GaussianBlur
*/

#include "../../include/Effects/GaussianBlur.hpp"

GaussianBlur::GaussianBlur(std::unique_ptr<Effect> imageEffect, double sigma, int radius)
{
    _imageEffect = std::move(imageEffect);
    _sigma = sigma;
    _radius = radius;
}

GaussianBlur::~GaussianBlur()
{
}

void GaussianBlur::GaussianBlur1D(Image &img, double sigma, int radius, bool horizontal)
{
    int size = 2 * radius + 1;
    std::vector<double> kernel(size);
    double sum = 0.0;

    for (int i = -radius; i <= radius; i++) {
        kernel[i + radius] = std::exp(-(i * i) / (2 * sigma * sigma)) / (sqrt(2 * M_PI) * sigma);
        sum += kernel[i + radius];
    }
    for (int i = 0; i < size; i++)
        kernel[i] /= sum;
    Image temp = img;
    for (size_t i = 0; i < img.size(); i++) {
        for (size_t j = 0; j < img[i].size(); j++) {
            double r = 0.0;
            double g = 0.0;
            double b = 0.0;
            double total = 0.0;
            for (int k = -radius; k <= radius; k++) {
                if (horizontal) {
                    if (j + k < img[i].size()) {
                        r += temp[i][j + k].getR() * kernel[k + radius];
                        g += temp[i][j + k].getG() * kernel[k + radius];
                        b += temp[i][j + k].getB() * kernel[k + radius];
                        total += kernel[k + radius];
                    }
                } else {
                    if (i + k < img.size()) {
                        r += temp[i + k][j].getR() * kernel[k + radius];
                        g += temp[i + k][j].getG() * kernel[k + radius];
                        b += temp[i + k][j].getB() * kernel[k + radius];
                        total += kernel[k + radius];
                    }
                }
            }
            img[i][j] = Color(r / total, g / total, b / total);
        }
    }
}

void GaussianBlur::applyEffect(Image &img)
{
    GaussianBlur1D(img, _sigma, _radius, true);
    GaussianBlur1D(img, _sigma, _radius, false);
}
