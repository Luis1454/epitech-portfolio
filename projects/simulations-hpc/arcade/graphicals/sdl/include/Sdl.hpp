/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** sdl2
*/

#ifndef SDL_HPP_
    #define SDL_HPP_

#include "../../IDisplayModule.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Sdl : public IDisplayModule {
    public:
        Sdl();
        ~Sdl();
        void setWindow() override;
        int is_lib() override;
        void drawWindow() override;
        void clear() override;
        void drawRect(int x, int y, int width, int height, Color color, int mode) override;
        void drawCircle(int x, int y, int radius, Color color, int mode) override;
        void drawText(int x, int y, std::string text, Color color, int mode) override;
        void loadFont(std::string path) override;
        int pollEvent() override;
        void closeWindow() override;
        int getKeys() override;
        int getWidth() override;
        int getHeight() override;
    private:
        SDL_Window *window;
        SDL_Surface *screen;
        SDL_Surface *textSurface;
        TTF_Font *font;
        SDL_Color textColor;
        SDL_Event event;
        int _key;
};

#endif /* SDL_HPP_ */
