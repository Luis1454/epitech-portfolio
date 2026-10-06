/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** GaussianBlur
*/

#ifndef GAUSSIANBLUR_HPP_
#define GAUSSIANBLUR_HPP_

#include "Effect.hpp"

class GaussianBlur : public Effect {
    public:
        GaussianBlur(std::unique_ptr<Effect> imageEffect, double sigma, int radius);
        ~GaussianBlur();

        void GaussianBlur1D(Image& img, double sigma, int radius, bool horizontal);
        void applyEffect(Image& img) override;

    private:
        std::unique_ptr<Effect> _imageEffect;
        double _sigma;
        int _radius;
};

#endif /* !GAUSSIANBLUR_HPP_ */
