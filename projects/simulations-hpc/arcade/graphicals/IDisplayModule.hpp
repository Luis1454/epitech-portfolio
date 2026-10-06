/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** IDisplayModule
*/

#ifndef IDisplayModule_HPP_
    #define IDisplayModule_HPP_

#include <iostream>
#include <vector>

enum Color {
    COLOR_Red,
    COLOR_Green,
    COLOR_Blue,
    COLOR_Yellow,
    COLOR_White,
    COLOR_Black,
    COLOR_Orange,
    COLOR_Pink,
    COLOR_Purple,
    COLOR_Cyan,
    COLOR_Brown,
    COLOR_Grey,
    COLOR_LightBlue,
    COLOR_AlphaBlack,
};

class IDisplayModule {
    public:
        virtual int is_lib() = 0;
        virtual void setWindow() = 0;
        virtual void drawWindow() = 0;
        virtual void clear() = 0;
        virtual void drawRect(int x, int y, int width, int height, Color color, int mode) = 0;
        virtual void drawCircle(int x, int y, int radius, Color color, int mode) = 0;
        virtual void drawText(int x, int y, std::string text, Color color, int mode) = 0;
        virtual void loadFont(std::string path) = 0;
        virtual int pollEvent() = 0;
        virtual void closeWindow() = 0;
        virtual int getKeys() = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
};

#endif /* IDisplayModule_HPP_ */
