/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Bloom
*/

#ifndef BLOOM_HPP_
#define BLOOM_HPP_

#include "Effect.hpp"

class Bloom : public Effect {
    public:
        Bloom(std::unique_ptr<Effect> imageEffect, double threshold, double sigma, int radius);

        void applyEffect(Image& img) override;

    private:
        std::unique_ptr<Effect> _imageEffect;
        double _threshold;
        double _sigma;
        int _radius;
};

#endif /* !BLOOM_HPP_ */
