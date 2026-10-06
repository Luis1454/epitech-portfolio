/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** ncurses
*/

#include "include/Ncurses.hpp"
#include <math.h>

extern "C" void *entryPoint()
{
    return new Ncurses();
}

Ncurses::Ncurses()
{
    input = 0;
}

Ncurses::~Ncurses()
{
    closeWindow();
}

void Ncurses::setWindow()
{
    initscr();
    start_color();
    init_pair(14,7,4);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_CYAN, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_BLACK, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(21, 1, 1);
    init_pair(22, 2, 2);
    init_pair(23, 4, 4);
    init_pair(24, 3, 3);
    init_pair(25, 7, 7);
    init_pair(26, COLOR_BLACK, COLOR_BLACK);
    init_pair(27, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(28, COLOR_CYAN, COLOR_CYAN);
    init_pair(29, 3, 3);
    init_pair(210, 7, COLOR_BLACK);
    init_pair(211, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(14));
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

int Ncurses::is_lib()
{
    return 1;
}

void Ncurses::drawWindow()
{
    refresh();
}

void Ncurses::clear()
{
    erase();
}

int Ncurses::getColor(Color color)
{
    switch (color) {
        case COLOR_Red:
            return 1;
        case COLOR_Green:
            return 2;
        case COLOR_Blue:
            return 3;
        case COLOR_Yellow:
            return 4;
        case COLOR_White:
            return 5;
        case COLOR_Black:
            return 6;
        case COLOR_Orange:
            return 7;
        case COLOR_Pink:
            return 7;
        case COLOR_Purple:
            return 7;
        case COLOR_Cyan:
            return 8;
        case COLOR_Brown:
            return 9;
        case COLOR_Grey:
            return 10;
        case COLOR_LightBlue:
            return 11;
        case COLOR_AlphaBlack:
            return 12;
    }
    return 5;
}

int getColorRect(Color color)
{
    switch (color) {
        case COLOR_Red:
            return 21;
        case COLOR_Green:
            return 22;
        case COLOR_Blue:
            return 23;
        case COLOR_Yellow:
            return 24;
        case COLOR_White:
            return 25;
        case COLOR_Black:
            return 26;
        case COLOR_Orange:
            return 27;
        case COLOR_Pink:
            return 27;
        case COLOR_Purple:
            return 27;
        case COLOR_Cyan:
            return 28;
        case COLOR_Brown:
            return 29;
        case COLOR_Grey:
            return 210;
        case COLOR_LightBlue:
            return 211;
        case COLOR_AlphaBlack:
            return 26;
    }
    return 5;
}

void Ncurses::drawRect(int x, int y, int width, int height, Color color, int mode)
{
    if (mode == 1) {
        x += getWidth() / 2;
        y += getHeight() / 2;
    }
    attrset(COLOR_PAIR(getColorRect(color)));
    if (mode == 2);
    else {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                mvprintw(y + j, x + i, " ");
            }
        }
    }
    attroff(COLOR_PAIR(getColorRect(color)));
}

void Ncurses::drawCircle(int x, int y, int radius, Color color, int mode)
{
    if (mode == 1) {
        x += getWidth() / 2;
        y += getHeight() / 2;
    }
    attron(COLOR_PAIR(getColor(color)));
    for (int i = 0; i < 360; i++)
        mvprintw(y + radius * sin(i), x + radius * cos(i), " ");
    attroff(COLOR_PAIR(getColor(color)));
}

void Ncurses::drawText(int x, int y, std::string text, Color color, int mode)
{
    if (mode == 1) {
        x += getWidth() / 2;
        y += getHeight() / 2;
    }
    attron(COLOR_PAIR(getColor(color)));
    move(y, x);
    printw("%s", text.c_str());
    attroff(COLOR_PAIR(getColor(color)));
}

void Ncurses::loadFont(std::string path)
{
    (void)path;
}

int Ncurses::pollEvent()
{
    _key = -1;
    input = getch();
    if (input == 258)
        _key = 74;
    if (input == 259)
        _key = 73;
    if (input == 261)
        _key = 72;
    if (input == 260)
        _key = 71;
    if (input == 10)
        _key = 58;
    if (input == 27)
        _key = 36;
    if (input == 32)
        _key = 57;
    for (int i = 0; i < 26; i++) {
        if (input == 97 + i)
            _key = i;
    }
    if (input == 263)
        _key = 59;
    return input;
}

void Ncurses::closeWindow()
{
    delwin(_window);
    endwin();
}

int Ncurses::getKeys()
{
    return _key;
}

int Ncurses::getWidth()
{
    return COLS;
}

int Ncurses::getHeight()
{
    return LINES;
}