/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include "../../IDisplayModule.hpp"

class Ncurses : public IDisplayModule  {
    public:
        Ncurses();
        ~Ncurses();
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
        WINDOW *_window;
        int _key;
        int input;
        int getColor(Color color);
};

#endif /* !NCURSES_HPP_ */
