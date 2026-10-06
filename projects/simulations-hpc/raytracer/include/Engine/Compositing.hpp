/*
** EPITECH PROJECT, 2024
** Compositing.hpp
** File description:
** Compositing
*/

#ifndef COMPOSITING_HPP_
    #define COMPOSITING_HPP_

    #include "../Physics/Color.hpp"

    class Compositing {
        public:
            Compositing();
            ~Compositing();
            static void GaussianBlur1D(Image &img, double sigma, int radius, bool horizontal);
            static void GaussianBlur(Image &img, double sigma, int radius);
            static void Bloom(Image &img, double threshold, double sigma, int radius);
            static void ChromaticAberration(Image &img, double force);
            static void Clamp(Image &img);
    };

#endif /* !COMPOSITING_HPP_ */
