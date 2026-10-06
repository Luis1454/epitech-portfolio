/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** sdl2
*/

#include "include/Sdl.hpp"
#include <iostream>
#include <SDL2/SDL.h>

extern "C" void *entryPoint()
{
    return new Sdl();
}

Sdl::Sdl()
{
    _key = 0;
}

Sdl::~Sdl()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Sdl::setWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
    screen = SDL_GetWindowSurface(window);
}

int Sdl::is_lib()
{
    return 1;
}

void Sdl::drawWindow()
{
    SDL_UpdateWindowSurface(window);
}

void Sdl::clear()
{
    SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0, 0, 0, 0));
}

SDL_Color getColor(Color color)
{
    switch (color) {
        case COLOR_Red:
            return {255, 0, 0, 0};
        case COLOR_Green:
            return {0, 255, 0, 0};
        case COLOR_Blue:
            return {0, 0, 255, 0};
        case COLOR_Yellow:
            return {255, 255, 0, 0};
        case COLOR_White:
            return {255, 255, 255, 0};
        case COLOR_Black:
            return {0, 0, 0, 0};
        case COLOR_Orange:
            return {255, 165, 0, 0};
        case COLOR_Pink:
            return {255, 192, 203, 0};
        case COLOR_Purple:
            return {128, 0, 128, 0};
        case COLOR_Cyan:
            return {0, 255, 255, 0};
        case COLOR_Brown:
            return {165, 42, 42, 0};
        case COLOR_Grey:
            return {128, 128, 128, 0};
        case COLOR_LightBlue:
            return {173, 216, 230, 0};
        case COLOR_AlphaBlack:
            return {0, 0, 0, 191};
    }
    return {255, 255, 255, 0};
}

void Sdl::drawRect(int x, int y, int width, int height, Color color, int mode)
{
    SDL_Rect rect = (SDL_Rect){0, 0, 0, 0};
    SDL_Color c = getColor(color);

    if (mode == 1) {
        x += getWidth() / 2 - width / 2;
        y += getHeight() / 2 - height / 2;
    }
    rect = {x*24, y*24, width*24, height*24};
    SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, c.r, c.g, c.b, c.a));
}

void Sdl::drawCircle(int x, int y, int radius, Color color, int mode)
{
    SDL_Color c = getColor(color);

    if (mode == 1) {
        x += getWidth() / 2;
        y += getHeight() / 2;
    }
    for (int i = 0; i < 360; i++) {
        int x1 = x + radius * cos(i);
        int y1 = y + radius * sin(i);
        SDL_Rect rect = {x1*24, y1*24, 24, 24};
        SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, c.r, c.g, c.b, c.a));
    }
}

void Sdl::drawText(int x, int y, std::string text, Color color, int mode)
{
    SDL_Rect textRect = {0, 0, 0, 0};

    textColor = getColor(color);
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if (textSurface == NULL) {
        std::cerr << "Error creating text surface: " << TTF_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(84);
    }
    if (mode == 1) {
        x = getWidth() / 2 - textSurface->w / 48;
        y += getHeight() / 2 - textSurface->h / 48;
    }
    textRect = {x*24, y*24, textSurface->w, textSurface->h};
    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
}

void Sdl::loadFont(std::string path)
{
    if (TTF_Init() < 0) {
        std::cerr << "Error initializing TTF: " << TTF_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(84);
    }
    font = TTF_OpenFont(path.c_str(), 24);
    if (font == NULL) {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(84);
    }
}

int Sdl::pollEvent()
{
    _key = -1;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 1;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    _key = 73;
                    break;
                case SDLK_DOWN:
                    _key = 74;
                    break;
                case SDLK_LEFT:
                    _key = 71;
                    break;
                case SDLK_RIGHT:
                    _key = 72;
                    break;
                case SDLK_RETURN:
                    _key = 58;
                    break;
                case SDLK_ESCAPE:
                    _key = 36;
                    break;
                case SDLK_SPACE:
                    _key = 57;
                    break;
                case SDLK_BACKSPACE:
                    _key = 59;
                    break;
                default:
                    break;
            }
            for (int i = 0; i < 26; i++) {
                if (event.key.keysym.sym == 97 + i)
                    _key = i;
            }
        }
    }
    return 0;
}

void Sdl::closeWindow()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Sdl::getKeys()
{
    return _key;
}

int Sdl::getWidth()
{
    return (screen->w) / 24;
}

int Sdl::getHeight()
{
    return (screen->h) / 24;
}
