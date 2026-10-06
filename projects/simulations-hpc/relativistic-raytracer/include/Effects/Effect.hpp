/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Effect
*/

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include <vector>
#include <memory>
#include "../Physics/Color.hpp"

class Effect {
    public:
        virtual void applyEffect(Image& img) = 0;
};

#endif /* !EFFECT_HPP_ */
