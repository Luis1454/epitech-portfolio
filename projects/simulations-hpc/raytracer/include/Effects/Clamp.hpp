/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Clamp
*/

#ifndef CLAMP_HPP_
#define CLAMP_HPP_

#include "Effect.hpp"

class Clamp : public Effect {
    public:
        Clamp();
        ~Clamp();

        void applyEffect(Image& img) override;

    private:
        std::unique_ptr<Effect> _imageEffect;
};

#endif /* !CLAMP_HPP_ */
