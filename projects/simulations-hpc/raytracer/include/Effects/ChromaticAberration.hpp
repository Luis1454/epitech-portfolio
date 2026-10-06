/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** ChromaticAberration
*/

#ifndef CHROMATICABERRATION_HPP_
#define CHROMATICABERRATION_HPP_

#include "Effect.hpp"

class ChromaticAberration : public Effect {
    public:
        ChromaticAberration(std::unique_ptr<Effect> imageEffect, double force);
        ~ChromaticAberration();

        void applyEffect(Image& img) override;

    private:
        std::unique_ptr<Effect> _imageEffect;
        double _force;
};

#endif /* !CHROMATICABERRATION_HPP_ */
